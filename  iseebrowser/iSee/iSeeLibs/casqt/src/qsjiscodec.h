#ifndef QSJISCODEC_H
#define QSJISCODEC_H

#include "qjpunicode.h"
#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QSjisCodec : public QTextCodec {
public:
    const char* name() { return "Shift_JIS"; }
	const Aliase* aliases();
    
    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState *);

    QSjisCodec();
    ~QSjisCodec();

protected:
    const QJpUnicodeConv *conv;
};

QT_END_NAMESPACE

#endif // QSJISCODEC_H
