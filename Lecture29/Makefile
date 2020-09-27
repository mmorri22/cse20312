# This is the Makefile for the CSE 20312 course Lecture 14 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
CLASSES := classes
PROG := programs
EXE := executables
OBJECTS := objects
	
	
	
# Command: make testMaxHeap1
testMaxHeap1Objs := $(OBJECTS)/testMaxHeap1.o 

testMaxHeap1: $(testMaxHeap1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap1 $(testMaxHeap1Objs)
	$(EXE)/./testMaxHeap1

$(OBJECTS)/testMaxHeap1.o: $(PROG)/testMaxHeap1.cpp $(CLASSES)/MaxHeap1.h
	$(PP) $(CXXFLAGS) -c $(PROG)/testMaxHeap1.cpp -o $@



# Command: make testMaxHeap2
testMaxHeap2Objs := $(OBJECTS)/testMaxHeap2.o 

testMaxHeap2: $(testMaxHeap2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap2 $(testMaxHeap2Objs)
	$(EXE)/./testMaxHeap2

$(OBJECTS)/testMaxHeap2.o: $(PROG)/testMaxHeap2.cpp $(CLASSES)/MaxHeap2.h
	$(PP) $(CXXFLAGS) -c $(PROG)/testMaxHeap2.cpp -o $@



# Command: make testMaxHeap3
testMaxHeap3Objs := $(OBJECTS)/testMaxHeap3.o 

testMaxHeap3: $(testMaxHeap3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap3 $(testMaxHeap3Objs)
	$(EXE)/./testMaxHeap3

$(OBJECTS)/testMaxHeap3.o: $(PROG)/testMaxHeap3.cpp $(CLASSES)/MaxHeap3.h
	$(PP) $(CXXFLAGS) -c $(PROG)/testMaxHeap3.cpp -o $@
	
	
	
# Command: make MaxHeapSort
MaxHeapSortObjs := $(OBJECTS)/MaxHeapSort.o 

MaxHeapSort: $(MaxHeapSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MaxHeapSort $(MaxHeapSortObjs)
	$(EXE)/./MaxHeapSort

$(OBJECTS)/MaxHeapSort.o: $(PROG)/MaxHeapSort.cpp $(CLASSES)/MaxHeap3.h
	$(PP) $(CXXFLAGS) -c $(PROG)/MaxHeapSort.cpp -o $@
	
	
	
# Command: make MinHeapSort
MinHeapSortObjs := $(OBJECTS)/MinHeapSort.o 

MinHeapSort: $(MinHeapSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MinHeapSort $(MinHeapSortObjs)
	$(EXE)/./MinHeapSort

$(OBJECTS)/MinHeapSort.o: $(PROG)/MinHeapSort.cpp $(CLASSES)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(PROG)/MinHeapSort.cpp -o $@
	
	
	
# Command: make PQTest
PQTestObjs := $(OBJECTS)/PQTest.o 

PQTest: $(PQTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PQTest $(PQTestObjs)
	$(EXE)/./PQTest

$(OBJECTS)/PQTest.o: $(PROG)/PQTest.cpp $(CLASSES)/PriorityQueue.h
	$(PP) $(CXXFLAGS) -c $(PROG)/PQTest.cpp -o $@
	


# Command: make FindKthLargest
FindKthLargestObjs := $(OBJECTS)/FindKthLargest.o 

FindKthLargest: $(FindKthLargestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindKthLargest $(FindKthLargestObjs)
	$(EXE)/./FindKthLargest

$(OBJECTS)/FindKthLargest.o: $(PROG)/FindKthLargest.cpp $(CLASSES)/MinHeap.h
	$(PP) $(CXXFLAGS) -c $(PROG)/FindKthLargest.cpp -o $@



# Make all
all: testMaxHeap1 testMaxHeap2



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables
	

# Make clean
clean :
	rm -rf *.o $(OBJECTS)/* $(EXE)/*
