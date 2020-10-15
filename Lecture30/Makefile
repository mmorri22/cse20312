# This is the Makefile for the CSE 20312 course - Lecture 30

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


# Command: make testRBTNode1
# Successfully create and allocate Red-Black Tree Nodes
testRBTNode1Objs := $(OBJ)/testRBTNode1.o

testRBTNode1: $(testRBTNode1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTNode1 $(testRBTNode1Objs)
	$(EXE)/./testRBTNode1

$(OBJ)/testRBTNode1.o: $(SRC)/testRBTNode1.cpp $(INC)/RBTNode1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTNode1.cpp -o $@
	
	
	
# Command: make testRBTNode2
# Obtain and print the node's uncle
testRBTNode2Objs := $(OBJ)/testRBTNode2.o

testRBTNode2: $(testRBTNode2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTNode2 $(testRBTNode2Objs)
	$(EXE)/./testRBTNode2

$(OBJ)/testRBTNode2.o: $(SRC)/testRBTNode2.cpp $(INC)/RBTNode2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTNode2.cpp -o $@


# Command: make testRBTNode1
# Test initial class for compilation
testRBTree1Objs := $(OBJ)/testRBTree1.o

testRBTree1: $(testRBTree1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree1 $(testRBTree1Objs)
	$(EXE)/./testRBTree1

$(OBJ)/testRBTree1.o: $(SRC)/testRBTree1.cpp $(INC)/RBTree1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree1.cpp -o $@



# Command: make testRBTNode2
# Test initial class for compilation
testRBTree2Objs := $(OBJ)/testRBTree2.o

testRBTree2: $(testRBTree2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree2 $(testRBTree2Objs)
	$(EXE)/./testRBTree2

$(OBJ)/testRBTree2.o: $(SRC)/testRBTree2.cpp $(INC)/RBTree2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree2.cpp -o $@	

	

# Make all
all: testRBTNode1Objs testRBTNode2Objs testRBTree1 testRBTree2

# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
