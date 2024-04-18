// CFantasyMovies.cpp
#include "CFantasyMovies.h"

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent)
{
  // Connect the signal from CReadFile to the slot in CFantasyMovies
  connect(&fileReader, &CReadFile::stacksFilled, this, &CFantasyMovies::onStacksFilled);
  // Connect the signal from QML to the slot in CFantasyMovies to trigger file reading
  connect(this, &CFantasyMovies::requestFileRead, &fileReader, &CReadFile::readFile);
}

void CFantasyMovies::processNumber(int number)
{
  QStack<QString> *selectedStack;
  if (number % 2 == 0)
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

  emit movieSelected(selectedMovie);

  // Move items back to original stack
  while (!stack_temp.isEmpty()) {
    selectedStack->push(stack_temp.pop());
  }
}

void CFantasyMovies::onStacksFilled()
{
  stack_odd = fileReader.getOddStack();
  stack_even = fileReader.getEvenStack();
}
