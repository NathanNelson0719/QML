// CFantasyMovies.h
#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include <QStack>
#include <QString>
#include "Creadfile.h"
#include "CRandom.h"
#include <QVariant>
class CFantasyMovies : public QObject
{
  Q_OBJECT
public:
  explicit CFantasyMovies(QObject *parent = nullptr);

    void setOddStack(QStack<QString> stack);
  void setEvenStack(QStack<QString> stack);
public slots:
  void processNumber(QString number);
  void onStacksFilled();

signals:
  void movieSelected(QVariant movie);
  void requestFileRead(QString fileName);

private:
  QStack<QString> stack_odd;
  QStack<QString> stack_even;
  CReadFile fileReader;
};

#endif // CFANTASYMOVIES_H
