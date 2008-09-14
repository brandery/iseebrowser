#ifndef QTSCIICODEC_H
#define QTSCIICODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QTsciiCodec : public QTextCodec {
public:
    ~QTsciiCodec();

	const char* name() { return "TSCII"; }

    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState *);
};

QT_END_NAMESPACE

#endif // QTSCIICODEC_H
