# This is the Makefile for the CSE 20312 course Lecture 27

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
	
	
	
# Command: make testMinHeap
testMinHeapObjs := $(OBJ)/testMinHeap.o 

testMinHeap: $(testMinHeapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMinHeap $(testMinHeapObjs)
	$(EXE)/./testMinHeap

$(OBJ)/testMinHeap.o: $(SRC)/testMinHeap.cpp $(INC)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMinHeap.cpp -o $@



# Command: make MinHeapSort
MinHeapSortObjs := $(OBJ)/MinHeapSort.o 

MinHeapSort: $(MinHeapSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MinHeapSort $(MinHeapSortObjs)
	$(EXE)/./MinHeapSort

$(OBJ)/MinHeapSort.o: $(SRC)/MinHeapSort.cpp $(INC)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MinHeapSort.cpp -o $@
	
	
	
# Command: make PQTest
PQTestObjs := $(OBJ)/PQTest.o 

PQTest: $(PQTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PQTest $(PQTestObjs)
	$(EXE)/./PQTest

$(OBJ)/PQTest.o: $(SRC)/PQTest.cpp $(INC)/PriorityQueue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PQTest.cpp -o $@
	


# Command: make FindKthLargest
FindKthLargestObjs := $(OBJ)/FindKthLargest.o 

FindKthLargest: $(FindKthLargestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindKthLargest $(FindKthLargestObjs)
	$(EXE)/./FindKthLargest

$(OBJ)/FindKthLargest.o: $(SRC)/FindKthLargest.cpp $(INC)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/FindKthLargest.cpp -o $@



# Command: make FindKMostFreq
FindKMostFreqObjs := $(OBJ)/FindKMostFreq.o 

FindKMostFreq: $(FindKMostFreqObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindKMostFreq $(FindKMostFreqObjs)
	$(EXE)/./FindKMostFreq

$(OBJ)/FindKMostFreq.o: $(SRC)/FindKMostFreq.cpp $(INC)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/FindKMostFreq.cpp -o $@




# Make all
all: testMinHeap MinHeapSort PQTest FindKthLargest FindKMostFreq



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
