#ifndef QISCIICODEC_H
#define QISCIICODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QIsciiCodec : public QTextCodec {
public:
    explicit QIsciiCodec(int i) : idx(i) {}
    ~QIsciiCodec();

    const char* name();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);

private:
    int idx;
};

QT_END_NAMESPACE

#endif // QISCIICODEC_H
