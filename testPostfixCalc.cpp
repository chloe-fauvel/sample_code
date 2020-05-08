// Chloe Fauvel, cff2aa
// testPostfixCalc.cpp
// Due: Tuesday, 9/17/19

#include "postfixCalculator.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;


int main() {

  string s;
  PostfixCalculator calc;
  
  while (cin >> s) {

    if (!s.compare("+")) {
	calc.add();
      }

    else if (!s.compare("-")) {
	calc.sub();
      }

    else if (!s.compare("*")) {
	calc.multiply();
      }

    else if (!s.compare("/")) {
	calc.divide();
      }

    else if (!s.compare("~")) {
	calc.negate();
      }

      else {
	// int i = stoi(s);
	int i = atoi(s.c_str());
	calc.pushNum(i);
      }
  }

  cout << calc.getTop()  << endl;

  return 0;
}
