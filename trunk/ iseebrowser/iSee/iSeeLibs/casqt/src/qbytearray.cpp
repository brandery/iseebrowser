QT_BEGIN_NAMESPACE

// String public functions
static int qAllocMore(int alloc, int extra)
{
    const int page = 1 << 12;
    int nalloc;
    alloc += extra;
    if (alloc < 1<<6) {
        nalloc = (1<<3) + ((alloc >>3) << 3);
    } else  {
        nalloc = (alloc < page) ? 1 << 3 : page;
        while (nalloc < alloc) {
            if (nalloc <= 0)
                return INT_MAX;
            nalloc <<= 1; // *= 2;
        }
    }
    return nalloc - extra;
}

static int qstrlen(const char* s)
{
	int r = 0;
	for (const char* p = s; *p; p++, r++);
	return r;
}

static int qwcslen(const ushort* s)
{
	int r = 0;
	for (const ushort* p = s; *p; p++, r++);
	return r;
}

// QByteArray
QByteArray::Data QByteArray::shared_null = { 1, 0, 0, shared_null.array, {0} };
QByteArray::Data QByteArray::shared_empty = { 1, 0, 0, shared_empty.array, {0} };

void QByteArray::reallocData(int alloc)
{
    if (d->ref != 1 || d->data != d->array) {
        Data *x = static_cast<Data *>(qMalloc(sizeof(Data) + alloc));
        if (!x)
            return;
        x->size = qMin(alloc, d->size);
        ::memcpy(x->array, d->data, x->size);
        x->array[x->size] = '\0';
        x->ref = 1;
        x->alloc = alloc;
        x->data = x->array;
        delete_();
        d = x;
    } else {
        Data *x = static_cast<Data *>(qRealloc(d, sizeof(Data) + alloc));
        if (!x)
            return;
        x->alloc = alloc;
        x->data = x->array;
        d = x;
    }
}

QByteArray::QByteArray(const char *s, int len)
: d(&shared_null)
{
	(void)append(s, len);
}

QByteArray &QByteArray::append(const char *s, int len)
{
	if (s) {
		if (len < 0) len = qstrlen(s);
        if (d->ref != 1 || d->size + len > d->alloc)
            reallocData(qAllocMore(d->size + len, sizeof(Data)));
        memcpy(d->data + d->size, s, len + 1); // include null terminator
        d->size += len;
    }
    return *this;
}

/*!
    \overload

    Prepends the string \a str to this byte array.
*/

QByteArray &QByteArray::prepend(const char *str)
{
    if (str) {
        int len = qstrlen(str);
        if (d->ref != 1 || d->size + len > d->alloc)
            reallocData(qAllocMore(d->size + len, sizeof(Data)));
        memmove(d->data+len, d->data, d->size);
        memcpy(d->data, str, len);
        d->size += len;
        d->data[d->size] = '\0';
    }
    return *this;
}

int QByteArray::indexOf(char ch, int from)
{
	if (from < 0)
        from = qMax(from + d->size, 0);
    if (from < d->size) {
        const char *n = d->data + from - 1;
        const char *e = d->data + d->size;
        while (++n != e)
        if (*n == ch)
            return  n - d->data;
    }
    return -1;
}

QByteArray QByteArray::mid(int pos, int len)
{
	if (d == &shared_null || d == &shared_empty || pos >= d->size)
        return QByteArray();
    if (len < 0)
        len = d->size - pos;
    if (pos < 0) {
        len += pos;
        pos = 0;
    }
    if (len + pos > d->size)
        len = d->size - pos;
    if (pos == 0 && len == d->size)
        return *this;
    return QByteArray(d->data + pos, len);
}

QByteArray QByteArray::trimmed() const
{
	if (d->size == 0)
        return *this;
    const char *s = d->data;
    if (!isspace(uchar(*s)) && !isspace(uchar(s[d->size-1])))
        return *this;
    int start = 0;
    int end = d->size - 1;
    while (start<=end && isspace(uchar(s[start])))  // skip white space from start
        start++;
    if (start <= end) {                          // only white space
        while (end && isspace(uchar(s[end])))           // skip white space from end
            end--;
    }
    int l = end - start + 1;
    if (l <= 0) {
		return QByteArray();
    }
    return QByteArray(s + start, l);
}

void QByteArray::resize(int size)
{
    if (size <= 0) {
		delete_();
		d = &shared_empty;
    } else if (d == &shared_null) {
        Data *x = static_cast<Data *>(qMalloc(sizeof(Data)+size));
        if (!x)
            return;
        x->ref = 1;
        x->alloc = x->size = size;
        x->data = x->array;
        x->array[size] = '\0';
        d = x;
    } else {
        if (d->ref != 1 || size > d->alloc || (size < d->size && size < d->alloc >> 1))
            reallocData(qAllocMore(size, sizeof(Data)));
        if (d->alloc >= size) {
            d->size = size;
            if (d->data == d->array) {
                d->array[size] = '\0';
            }
        }
    }
}

QT_END_NAMESPACE
