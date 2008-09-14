#include "qeucjpcodec.h"

QT_BEGIN_NAMESPACE

static const uchar Esc = 0x1b;
static const uchar Ss2 = 0x8e;     // Single Shift 2
static const uchar Ss3 = 0x8f;     // Single Shift 3

#define        IsKana(c)           (((c) >= 0xa1) && ((c) <= 0xdf))
#define        IsEucChar(c)        (((c) >= 0xa1) && ((c) <= 0xfe))

#define        QValidChar(u)       ((u) ? ((ushort)(u)) : (QChar::ReplacementCharacter))

/*!
  Constructs a QEucJpCodec.
*/
QEucJpCodec::QEucJpCodec() : conv(QJpUnicodeConv::newConverter(QJpUnicodeConv::Default))
{
}

/*!
  Destroys the codec.
*/
QEucJpCodec::~QEucJpCodec()
{
    delete (QJpUnicodeConv*)conv;
    conv = 0;
}

QByteArray QEucJpCodec::convertFromUnicode(const ushort *uc, int len, ConverterState *state)
{
    char replacement = '?';
    if (state) {
        if (state->flags & ConvertInvalidToNull)
            replacement = 0;
    }
    int invalid = 0;

    int rlen = 3*len + 1;
    QByteArray rstr;
    rstr.resize(rlen);
    uchar* cursor = (uchar*)rstr.data();
    for (int i = 0; i < len; i++) {
        QChar ch = uc[i];
        uint j;
        if (ch.unicode() < 0x80) {
            // ASCII
            *cursor++ = ch.cell();
        } else if ((j = conv->unicodeToJisx0201(ch.row(), ch.cell())) != 0) {
            if (j < 0x80) {
                // JIS X 0201 Latin ?
                *cursor++ = j;
            } else {
                // JIS X 0201 Kana
                *cursor++ = Ss2;
                *cursor++ = j;
            }
        } else if ((j = conv->unicodeToJisx0208(ch.row(), ch.cell())) != 0) {
            // JIS X 0208
            *cursor++ = (j >> 8)   | 0x80;
            *cursor++ = (j & 0xff) | 0x80;
        } else if ((j = conv->unicodeToJisx0212(ch.row(), ch.cell())) != 0) {
            // JIS X 0212
            *cursor++ = Ss3;
            *cursor++ = (j >> 8)   | 0x80;
            *cursor++ = (j & 0xff) | 0x80;
        } else {
            // Error
            *cursor++ = replacement;
            ++invalid;
        }
    }
    rstr.resize(cursor - (uchar*)rstr.constData());

    if (state) {
        state->invalidChars += invalid;
    }
    return rstr;
}


QString QEucJpCodec::convertToUnicode(const char* chars, int len, ConverterState *state)
{
    uchar buf[2] = {0, 0};
    int nbuf = 0;
    ushort replacement = QChar::ReplacementCharacter;
    if (state) {
        if (state->flags & ConvertInvalidToNull)
            replacement = QChar::Null;
        nbuf = state->remainingChars;
        buf[0] = state->state_data[0];
        buf[1] = state->state_data[1];
    }
    int invalid = 0;

    QString result;
	result.resize(len);
	ushort* cursor = result.data();

    for (int i=0; i<len; i++) {
        uchar ch = chars[i];
        switch (nbuf) {
        case 0:
            if (ch < 0x80) {
                // ASCII
                *cursor++ = ushort(ch);
            } else if (ch == Ss2 || ch == Ss3) {
                // JIS X 0201 Kana or JIS X 0212
                buf[0] = ch;
                nbuf = 1;
            } else if (IsEucChar(ch)) {
                // JIS X 0208
                buf[0] = ch;
                nbuf = 1;
            } else {
                // Invalid
                *cursor++ = replacement;
                ++invalid;
            }
            break;
        case 1:
            if (buf[0] == Ss2) {
                // JIS X 0201 Kana
                if (IsKana(ch)) {
                    uint u = conv->jisx0201ToUnicode(ch);
                    *cursor++ = QValidChar(u);
                } else {
                    *cursor++ = replacement;
                    ++invalid;
                }
                nbuf = 0;
            } else if (buf[0] == Ss3) {
                // JIS X 0212-1990
                if (IsEucChar(ch)) {
                    buf[1] = ch;
                    nbuf = 2;
                } else {
                    // Error
                    *cursor++ = replacement;
                    ++invalid;
                    nbuf = 0;
                }
            } else {
                // JIS X 0208-1990
                if (IsEucChar(ch)) {
                    uint u = conv->jisx0208ToUnicode(buf[0] & 0x7f, ch & 0x7f);
                    *cursor++ = QValidChar(u);
                } else {
                    // Error
                    *cursor++ = replacement;
                    ++invalid;
                }
                nbuf = 0;
            }
            break;
        case 2:
            // JIS X 0212
            if (IsEucChar(ch)) {
                uint u = conv->jisx0212ToUnicode(buf[1] & 0x7f, ch & 0x7f);
                *cursor++ = QValidChar(u);
            } else {
                *cursor++ = replacement;
                ++invalid;
            }
            nbuf = 0;
        }
    }
	result.resize(cursor - result.constData());

    if (state) {
        state->remainingChars = nbuf;
        state->state_data[0] = buf[0];
        state->state_data[1] = buf[1];
        state->invalidChars += invalid;
    }
    return result;
}

QT_END_NAMESPACE