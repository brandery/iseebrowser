#ifndef QEUCJPCODEC_H
#define QEUCJPCODEC_H

#include "qjpunicode.h"
#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QEucJpCodec : public QTextCodec {
public:
    const char* name() { return "EUC-JP"; }

    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState *);

    QEucJpCodec();
    ~QEucJpCodec();

protected:
    const QJpUnicodeConv *conv;
};

QT_END_NAMESPACE

#endif // QEUCJPCODEC_H
