// CFantasyMovies.cpp
#include "CFantasyMovies.h"

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent)
{
}

void CFantasyMovies::processNumber(QString number)
{
    CRandom random;
    int num = number.toInt();
    if (currentNumber != num)
    {
        currentNumber = num;
        QStack<QString> *selectedStack;
        if (num % 2 == 0)
        {
            selectedStack = &stack_even;
            if(selectedStack->isEmpty()){
                selectedStack = &stack_odd;
            }

        }
        else{
            selectedStack = &stack_odd;
            if(selectedStack->isEmpty()){
                selectedStack = &stack_even;
            }
        }
        if (selectedStack->isEmpty()) {
            emit movieSelected("No other available films");
            return;
        }

        //get random movie title from stack
        QString selectedMovie = random.getRandomTitle((*selectedStack));

        // Temporary stack to hold other items
        QStack<QString> stack_temp;
        while (!selectedStack->isEmpty() && selectedStack->top() != selectedMovie) {
            stack_temp.push(selectedStack->top());
            selectedStack->pop();
        }
        selectedStack->pop(); // remove movie from list.
        emit movieSelected(QVariant(selectedMovie));

        // Move items back to original stack
        while (!stack_temp.isEmpty()) {
            selectedStack->push(stack_temp.top());
            stack_temp.pop();
        }
    }

}
void CFantasyMovies::setOddStack(QStack<QString> stack){
        stack_odd = stack;
 }

void CFantasyMovies::setEvenStack(QStack<QString> stack){
        stack_even = stack;
    }
\
