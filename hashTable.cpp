// Chloe Fauvel, cff2aa
// hashTable.cpp
// Due: Tuesday, 10/22/19

#include "hashTable.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

bool checkprime(unsigned int p);
unsigned int primenumber(unsigned int n);


HashTable::HashTable() {
  tableSize = 50287;
  table.reserve(tableSize);
  table.assign(tableSize, "");

  /*
  for (unsigned int i=0; i<23; i++) {
    powers[i]=pow(37,i);
  }
  */

 
  powers[0]=1;
  
  for (unsigned int i=1; i<23; i++) {
    powers[i]=powers[i-1]*37;
  }  
  
}

HashTable::HashTable(string filename) {

  /*
  for (unsigned int i=0; i<23; i++) {
    powers[i]=pow(37,i);
  }
  */


  powers[0]=1;
  
  for (unsigned int i=1; i<23; i++) {
    powers[i]=powers[i-1]*37;
  }  

  unsigned int numOfWords=0;

  ifstream dict(filename.c_str());
  string line;

  while (!dict.eof()) {
    numOfWords++;
    getline(dict,line);
  }
  numOfWords = numOfWords-1;
  numOfWords = 6*numOfWords;
  tableSize = primenumber(numOfWords);
  // cout << numOfWords << endl; // should be 3067

  table.reserve(tableSize);
  // cout << (unsigned int) table.capacity() << endl; // should be 3067

  table.assign(tableSize, "");
}


unsigned int HashTable::getTableSize() {
  return tableSize;
}

string HashTable::getValueAt(unsigned int i) {
  return table[i];
}

vector<string> HashTable::getOutput(){
  return output;
}

unsigned int HashTable::hashOutput(string str) {
  
  unsigned long long int sum=0;
  
  for (int j=0; j<str.length(); j++) {
    // cout << powers[j] << endl;
    sum += (int(str.at(j))-65)*powers[j];
  }
  
  return sum;
}


void HashTable::insert(string str) {

  // cap letters ASCII range = 65-90
  // lower case letters ASCII range = 97-122
  
  bool valid=true;

  // go through string & check if there are any invalid characters
    for (int i=0; i<str.length(); i++) {
      if ((int(str.at(i)) < 65) |
	  ((int(str.at(i)) > 90) && (int(str.at(i)) < 97))  |
	  (int(str.at(i)) > 122)) {
	valid = false;
      }
    }
    
    if (valid == true && find(str) == false) {

      unsigned int k = hashOutput(str);
      unsigned int index = k % tableSize;
    
      if (table[index].length() != 0) {
	while (table[index].length() != 0) {
	  k++;
	  index = k % tableSize;
	}
      }
      table[index] = str;
    }
}


bool HashTable::find(string str) {

  bool valid=true;

  for (int i=0; i<str.length(); i++) {
    if ((int(str.at(i)) < 65) |
        ((int(str.at(i)) > 90) && (int(str.at(i)) < 97))  |
	(int(str.at(i)) > 122)) {
      return valid = false;
    }
  }

  if (valid == true) {

    unsigned int k = hashOutput(str);
    unsigned int index = k % tableSize;
    
    if (table[index].length() == 0) {
      return false;
    }
    else if (table[index] != str) {

      while (table[index].length() != 0) {
	k++;
	index = k % tableSize;
	string str2 = table[index];
	if (str == str2) {
	  return true;
	}
      }
      return false;
    }
    else {
      return true;
    }
  }
  
}


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

unsigned int primenumber(unsigned int n) {
  
  while ( !checkprime(++n) );
  return n;
}
