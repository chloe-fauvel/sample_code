// Chloe Fauvel, cff2aa
// stack.cpp
// Due: Friday, 9/20/19

#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() {
  head = new StackNode;
}


Stack::~Stack() {
  delete head;
}


void Stack::push(int e) {
  StackNode * node = new StackNode();
  node->value = e;
  node->next = head;
  head = node;
}

void Stack::pop() {

  if (isEmpty() == true) {
    exit(-1);
  }

  else {
    StackNode * old = head;
    head = head->next;
    delete old;
  }
}

int Stack::top() {

  if (isEmpty() == true) {
    exit(-1);
  }

  else {
    return head->retrieveCurrent();
  }

}

bool Stack::isEmpty() {
  if (head == NULL) {
    return true;
  }
  else {
    return false;
  }
}






