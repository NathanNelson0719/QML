#include "TestSignal.h"
TestSignal::TestSignal(QObject *parent) : QObject (parent)
{

}

void TestSignal::getEvenTitle(){
}

void TestSignal::getOddTitle(){
}

void TestSignal::setEvenStack(QStack<QString> stack){
    stack_even = stack;
}

void TestSignal::setOddStack(QStack<QString> stack){
    stack_odd = stack;
}
