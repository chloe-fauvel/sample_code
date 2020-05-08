#Chloe Fauvel, cff2aa, 2:00-3:15 pm
#Makefile
#Due: Tuesday, 10/22/19

CXX=clang++
CXXFLAGS=-Wall -std=c++11 -lrt -O2
OFILES=timer.o hashTable.o wordPuzzle.o

.SUFFIXES: .o .cpp

executable: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

clean:
	-rm -f *.o *~ a.out 

timer.o: timer.cpp timer.h
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp

