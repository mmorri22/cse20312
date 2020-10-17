# This is the Makefile for the CSE 20312 course - Lecture 38

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


	
# Command: make testBH
# Tests the Treap Insert Results
testBHObjs := $(OBJ)/testBH.o 

testBH: $(testBHObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBH $(testBHObjs)
	$(EXE)/./testBH

$(OBJ)/testBH.o: $(SRC)/testBH.cpp $(INC)/BinomialHeap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBH.cpp -o $@



# Command: make testPQ
# Tests the Treap Insert Results
testPQObjs := $(OBJ)/testPQ.o 

testPQ: $(testPQObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testPQ $(testPQObjs)
	$(EXE)/./testPQ

$(OBJ)/testPQ.o: $(SRC)/testPQ.cpp $(INC)/PriorityQueue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testPQ.cpp -o $@


# Command: make PriorityTest
# Tests the Treap Insert Results
PriorityTestObjs := $(OBJ)/PriorityTest.o 

PriorityTest: $(PriorityTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PriorityTest $(PriorityTestObjs)
	$(EXE)/./PriorityTest

$(OBJ)/PriorityTest.o: $(SRC)/PriorityTest.cpp $(INC)/PriorityQueue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PriorityTest.cpp -o $@

# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)

# Make all
all: testPQ testBH

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
