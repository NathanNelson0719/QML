// CRandom.h
#ifndef CRANDOM_H
#define CRANDOM_H

#include <cstdlib>
#include <ctime>
#include <QString>
#include <QObject>
#include <QStack>
class CRandom
{
public:
    explicit CRandom();
    int getRandomNumber(int max);
    QString getRandomTitle(QStack<QString> &stack);
};

#endif // CRANDOM_H
