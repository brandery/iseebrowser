#ifndef QBIG5CODEC_H
#define QBIG5CODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QBig5Codec : public QTextCodec {
public:
    const char* name() { return "Big5"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

class QBig5hkscsCodec : public QTextCodec {
public:
	const char* name() { return "Big5-HKSCS"; }

    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

QT_END_NAMESPACE

#endif // QBIG5CODEC_H
