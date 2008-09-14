#ifndef QTEXTBOUNDARYFINDER_H
#define QTEXTBOUNDARYFINDER_H

#include "qstring.h"

QT_BEGIN_NAMESPACE

class QTextBoundaryFinderPrivate;

class Q_CORE_EXPORT QTextBoundaryFinder
{
public:
    QTextBoundaryFinder();
    QTextBoundaryFinder(const QTextBoundaryFinder &other);
    QTextBoundaryFinder &operator=(const QTextBoundaryFinder &other);
    ~QTextBoundaryFinder();

    enum BoundaryType {
        Grapheme,
        Word,
        Line,
        Sentence
    };

    enum BoundaryReason {
        NotAtBoundary = 0,
        StartWord = 1,
        EndWord = 2
        //Hyphen
    };
	typedef uint BoundaryReasons;

    QTextBoundaryFinder(BoundaryType type, const QString &string);
    QTextBoundaryFinder(BoundaryType type, const ushort* chars, int len, unsigned char *buffer = 0, int bufferSize = 0);

	inline bool isValid() const { return d != 0; }

    inline BoundaryType type() const { return t; }
    QString string() const;

    void toStart();
    void toEnd();
    int position() const;
    void setPosition(int position);

    int toNextBoundary();
    int toPreviousBoundary();

    bool isAtBoundary() const;
    BoundaryReasons boundaryReasons() const;

private:
    BoundaryType t;
    QString s;
    const ushort* chars;
    int length;
    int pos;
    uint freePrivate : 1;
    uint unused : 31;
    QTextBoundaryFinderPrivate *d;
};

QT_END_NAMESPACE

#endif
