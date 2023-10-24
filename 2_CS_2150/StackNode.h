// Chloe Fauvel, cff2aa
// StackNode.h
// Due: Friday, 9/20/19

#include <iostream>
using namespace std;

#ifndef STACKNODE_H
#define STACKNODE_h

class StackNode {

 public:
  StackNode();
  int retrieveCurrent();


 private:
  int value;
  StackNode * next;

friend class Stack;

};

#endif
