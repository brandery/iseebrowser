#ifndef QGB18030CODEC_H
#define QGB18030CODEC_H

#include "qtextcodec.h"

QT_BEGIN_NAMESPACE

class QGb18030Codec : public QTextCodec {
public:
    QGb18030Codec();

	const char* name() { return "GB18030"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

class QGbkCodec : public QGb18030Codec {
public:
    QGbkCodec();

	const char* name() { return "GBK"; }
	const Aliase* aliases();

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

class QGb2312Codec : public QGb18030Codec {
public:
    QGb2312Codec();

	const char* name() { return "GB2312"; }

    QString convertToUnicode(const char*, int, ConverterState*);
    QByteArray convertFromUnicode(const ushort*, int, ConverterState*);
};

QT_END_NAMESPACE

#endif // QGB18030CODEC_H
