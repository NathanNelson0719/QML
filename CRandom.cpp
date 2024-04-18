// CRandom.cpp
#include "CRandom.h"

CRandom::CRandom()
{
  srand(time(nullptr));
}

int CRandom::getRandomNumber(int max)
{
  return rand() % max;
}
