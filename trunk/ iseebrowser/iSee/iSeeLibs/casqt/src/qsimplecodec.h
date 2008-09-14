#ifndef QSIMPLECODEC_H
#define QSIMPLECODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QSimpleTextCodec: public QTextCodec
{
public:
    enum { numSimpleCodecs = 30 };
    explicit QSimpleTextCodec(int);
    ~QSimpleTextCodec();

	const char* name();
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

private:
    int forwardIndex;
    QByteArray* reverseMap;
};

QT_END_NAMESPACE

#endif // QSIMPLECODEC_H
