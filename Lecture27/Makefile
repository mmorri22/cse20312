# This is the Makefile for the CSE 20312 course Lecture 26

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
	
	
	
# Command: make testMaxHeap1
testMaxHeap1Objs := $(OBJ)/testMaxHeap1.o 

testMaxHeap1: $(testMaxHeap1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap1 $(testMaxHeap1Objs)
	$(EXE)/./testMaxHeap1

$(OBJ)/testMaxHeap1.o: $(SRC)/testMaxHeap1.cpp $(INC)/MaxHeap1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap1.cpp -o $@



# Command: make testMaxHeap2
testMaxHeap2Objs := $(OBJ)/testMaxHeap2.o 

testMaxHeap2: $(testMaxHeap2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap2 $(testMaxHeap2Objs)
	$(EXE)/./testMaxHeap2

$(OBJ)/testMaxHeap2.o: $(SRC)/testMaxHeap2.cpp $(INC)/MaxHeap2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap2.cpp -o $@



# Command: make testMaxHeap3
testMaxHeap3Objs := $(OBJ)/testMaxHeap3.o 

testMaxHeap3: $(testMaxHeap3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap3 $(testMaxHeap3Objs)
	$(EXE)/./testMaxHeap3

$(OBJ)/testMaxHeap3.o: $(SRC)/testMaxHeap3.cpp $(INC)/MaxHeap3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap3.cpp -o $@
	
	
	
# Command: make MaxHeapSort
MaxHeapSortObjs := $(OBJ)/MaxHeapSort.o 

MaxHeapSort: $(MaxHeapSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MaxHeapSort $(MaxHeapSortObjs)
	$(EXE)/./MaxHeapSort

$(OBJ)/MaxHeapSort.o: $(SRC)/MaxHeapSort.cpp $(INC)/MaxHeap3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MaxHeapSort.cpp -o $@
	
	
	
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



# Make all
all: testMaxHeap1 testMaxHeap2



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
