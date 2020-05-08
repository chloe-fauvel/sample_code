// Chloe Fauvel, cff2aa
// StackNode.cpp
// Due: Friday, 9/20/19

#include "StackNode.h"
#include <iostream>
using namespace std;

StackNode::StackNode() {
  value = 0;
  next = NULL;
}

int StackNode::retrieveCurrent() {
  return value;
}
