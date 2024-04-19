// CFantasyMovies.cpp
#include "CFantasyMovies.h"

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent)
{
}

void CFantasyMovies::processNumber(QString number)
{
    int num = number.toInt();
  QStack<QString> *selectedStack;
  if (num % 2 == 0)
    selectedStack = &stack_even;
  else
    selectedStack = &stack_odd;

  if (selectedStack->isEmpty()) {
    emit movieSelected("No other available films");
    return;
  }

  CRandom random;
  int index = random.getRandomNumber(selectedStack->size());
  QString selectedMovie = selectedStack->at(index);

  // Temporary stack to hold other items
  QStack<QString> stack_temp;
  while (!selectedStack->isEmpty() && selectedStack->top() != selectedMovie) {
      stack_temp.push(selectedStack->pop());
  }

  emit movieSelected(QVariant(selectedMovie));

  // Move items back to original stack
  while (!stack_temp.isEmpty()) {
    selectedStack->push(stack_temp.pop());
  }
}


void CFantasyMovies::setOddStack(QStack<QString> stack){
    stack_odd = stack;
}
void CFantasyMovies::setEvenStack(QStack<QString> stack){
    stack_even = stack;
}

void CFantasyMovies::onStacksFilled()
{
  stack_odd = fileReader.getStackOdd();
  stack_even = fileReader.getStackEven();
}
