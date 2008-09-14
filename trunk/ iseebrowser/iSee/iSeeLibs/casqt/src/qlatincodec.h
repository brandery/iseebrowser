#ifndef QLATINCODEC_H
#define QLATINCODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QLatin1Codec : public QTextCodec
{
public:
    ~QLatin1Codec();

	const char* name() { return "ISO-8859-1"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState *);
};



class QLatin15Codec: public QTextCodec
{
public:
    ~QLatin15Codec();

	const char* name() { return "ISO-8859-15"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState *);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState *);
};

QT_END_NAMESPACE

#endif // QLATINCODEC_H
