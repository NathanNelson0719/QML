// CFantasyMovies.h
#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include <QStack>
#include <QString>
#include "CReadFile.h"
#include "CRandom.h"

class CFantasyMovies : public QObject
{
  Q_OBJECT
public:
  explicit CFantasyMovies(QObject *parent = nullptr);

public slots:
  void processNumber(int number);
  void onStacksFilled();

signals:
  void movieSelected(Qstring movie);
  void requestFileRead(Qstring fileName);

private:
  QStack<QString> stack_odd;
  QStack<QString> stack_even;
  CReadFile fileReader;
};

#endif // CFANTASYMOVIES_H
