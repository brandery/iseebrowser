#ifndef QEUCKRCODEC_H
#define QEUCKRCODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QEucKrCodec : public QTextCodec {
public:
    const char* name() { return "EUC-KR"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

class QCP949Codec : public QTextCodec {
public:
    const char* name() { return "cp949"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

QT_END_NAMESPACE

#endif // QEUCKRCODEC_H
