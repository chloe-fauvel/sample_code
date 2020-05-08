// Chloe Fauvel, cff2aa
// hashtable.h
// Due: Tuesday, 10/22/19

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class HashTable {
  
 public:
  HashTable();
  HashTable(string filename);
  
  void insert(string str);
  bool find(string str);
  unsigned int getTableSize();
  string getValueAt(unsigned int i);
vector<string> getOutput();

  
 private:
  vector<string> table;
vector<string> output;
  unsigned int powers[22];
  unsigned int tableSize;
  unsigned int hashOutput(string str);
  
};

#endif
