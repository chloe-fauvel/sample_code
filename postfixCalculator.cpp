// Chloe Fauvel, cff2aa
// postfixCalculator.cpp
// Due: Tuesday, 9/17/19

#include "postfixCalculator.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

PostfixCalculator::PostfixCalculator() {
}


PostfixCalculator::~PostfixCalculator() {
}


void PostfixCalculator::add() {
  int x = stack.top();
  stack.pop();
  int y = stack.top();
  stack.pop();
  int z = x+y;
  stack.push(z);
}

void PostfixCalculator::sub() {
  int x = stack.top();
  stack.pop();
  int y = stack.top();
  stack.pop();
  int z = y-x;
  stack.push(z);
}

void PostfixCalculator::multiply() {
  int x = stack.top();
  stack.pop();
  int y = stack.top();
  stack.pop();
  int z = x*y;
  stack.push(z);
}

void PostfixCalculator::divide() {
  int x = stack.top();
  stack.pop();
  int y = stack.top();
  stack.pop();
  int z = y/x;
  stack.push(z);
}


void PostfixCalculator::negate() {
  int x = stack.top();
  stack.pop();
  x = (-1)*x;
  stack.push(x);
}

void PostfixCalculator::pushNum(int e) {
  stack.push(e);
}

int PostfixCalculator::getTop() {
  return stack.top();
}


// if pop() or top() are called on an empty stack, terminate the program with the function call exit(-1) which is from the <cstdlib> library



