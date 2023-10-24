// Chloe Fauvel, cff2aa
// stack.h
// Due: Friday, 9/18/19

#include <iostream>
#include <string>
using namespace std;

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

class Stack {

 public:
Stack();
~Stack();
  void push(int e);
  int top();
  void pop();
bool isEmpty();


 private:
StackNode * head;

};

#endif
