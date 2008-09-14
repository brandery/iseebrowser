#ifndef QUTFCODEC_H
#define QUTFCODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QUtf8Codec : public QTextCodec {
public:
    ~QUtf8Codec();

	const char* name() { return "UTF-8"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

    void convertToUnicode(QString *, const char*, int, ConverterState*);
};

class QUtf16Codec : public QTextCodec {
protected:
    enum Endianness {
        Detect,
        BE,
        LE
    };
public:
    QUtf16Codec() { e = Detect; }
    ~QUtf16Codec();

	const char* name() { return "UTF-16"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

protected:
    Endianness e;
};

class QUtf16BECodec : public QUtf16Codec {
public:
    QUtf16BECodec() : QUtf16Codec() { e = BE; }
    const char* name() { return "UTF-16BE"; }
	const Aliase* aliases() { return QTextCodec::aliases(); }
};

class QUtf16LECodec : public QUtf16Codec {
public:
    QUtf16LECodec() : QUtf16Codec() { e = LE; }
    const char* name() { return "UTF-16LE"; }
	const Aliase* aliases() { return QTextCodec::aliases(); }
};

class QUtf32Codec : public QTextCodec {
protected:
    enum Endianness {
        Detect,
        BE,
        LE
    };
public:
    QUtf32Codec() { e = Detect; }
    ~QUtf32Codec();

    const char* name() { return "UTF-32"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

protected:
    Endianness e;
};

class QUtf32BECodec : public QUtf32Codec {
public:
    QUtf32BECodec() : QUtf32Codec() { e = BE; }
    const char* name() { return "UTF-32BE"; }
};

class QUtf32LECodec : public QUtf32Codec {
public:
    QUtf32LECodec() : QUtf32Codec() { e = LE; }
    const char* name() { return "UTF-32LE"; }
};

QT_END_NAMESPACE

#endif // QUTFCODEC_H
