#ifndef QJISCODEC_H
#define QJISCODEC_H

#include "qjpunicode.h"
#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QJisCodec : public QTextCodec {
public:
    const char* name() { return "ISO-2022-JP"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

    QJisCodec();
    ~QJisCodec();

protected:
    const QJpUnicodeConv *conv;
};

QT_END_NAMESPACE

#endif // QJISCODEC_H
