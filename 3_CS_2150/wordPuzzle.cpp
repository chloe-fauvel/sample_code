// Chloe Fauvel, cff2aa
// wordPuzzle.cpp
// Due: Tuesday, 10/22/19

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "timer.h"
#include "hashTable.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];


bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


// command-line parameters = C-style array strings
// first command-line parameter: dictionary filename
// secondary command-line parameter: grid filename
int main(int argc, char** argv) {
  
  // build grid
  string gridName=argv[2];
  int rows=1, cols=1;
  readInGrid(gridName, rows, cols);

  
  // build hash table
  string filename = argv[1];
  HashTable hashTable(filename);
  // cout << "Hashtable size: " << hashTable.getTableSize() << endl;
  
  ifstream dict;
  dict.open(argv[1]);

  string line;
  string word;
  
  while (!dict.eof()) {
    dict >> word;
    getline(dict,line);
    hashTable.insert(word);
  }

  dict.close();

  /*
  for (unsigned int q=0; q<hashTable.getTableSize(); q++) {
    cout << "HashTable string at index " << q << " is " <<
      hashTable.getValueAt(q) << endl;
  }
  */

  
  // timer call
  timer timer;
  timer.start();

  // code to find word in the grid -- getWordInGrid
  unsigned int sum=0;
  vector<string> cOut = hashTable.getOutput();
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols; c++) {
      for (int d=0; d<8; d++) {
	for (int l=3; l<=min(max(rows,cols),22); l++) {
	  char* gridWord = getWordInGrid(r,c,d,l,rows,cols);
	  if ((((int) strlen(gridWord))>=3) && (((int) strlen(gridWord))==l)) {
	    bool inDict=hashTable.find((string) gridWord);
	    if (inDict == true) {
	      sum++;
	      if (d==0) {
		//cout << "N ("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "N ("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==1) {
		//cout << "NE("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "NE("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==2) {
		//cout << "E ("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "E ("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==3) {
		//cout << "SE("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "SE("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==4) {
		//cout << "S ("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "S ("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==5) {
		//cout << "SW("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "SW("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else if (d==6) {
		//cout << "W ("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "W ("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	      else {
		//cout << "NW("<<r<<", "<<c<<"):   "<<gridWord<<endl;
		string wordStr = "NW("+to_string(r)+", "+to_string(c)+"):   "+gridWord+"\n";
		cOut.push_back(wordStr);
	      }
	    }
	  }
	}
      }
    }
  }

  timer.stop();
  
  for (int a=0; a<cOut.size(); a++) {
    cout << cOut[a];
  }
  
  cout << sum << " words found" << endl;

  // timer call
  cout << "Found all words in " << timer.getTime() << " seconds" <<endl;
}


/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}



