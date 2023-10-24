// Chloe Fauvel, cff2aa
// postfixCalculator.h
// Due: Tuesday, 9/17/19

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

class PostfixCalculator {

 public:
  PostfixCalculator();
~PostfixCalculator();
 void pushNum(int e);
 int getTop();
  void add();
  void sub();
  void multiply();
  void divide();
  void negate();

 private:
  Stack stack;

};

#endif
