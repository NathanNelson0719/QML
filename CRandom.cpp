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

//select a random movie in the stack.
QString CRandom::getRandomTitle(QStack<QString> &stack){
    int index = getRandomNumber(stack.size());

    return stack.at(index);
}
