# This is the Makefile for the CSE 20312 course - Optional 06 Lecture

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


# Command: make testAVL1
# Test AVL Tree - 1
testAVL1Objs := $(OBJ)/testAVL1.o 

testAVL1: $(testAVL1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testAVL1 $(testAVL1Objs)
	$(EXE)/./testAVL1

$(OBJ)/testAVL1.o: $(SRC)/testAVL1.cpp $(INC)/AVLTree1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testAVL1.cpp -o $@



# Command: make testAVL
# Test AVL Tree - With Full Balance
testAVLObjs := $(OBJ)/testAVL.o 

testAVL: $(testAVLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testAVL $(testAVLObjs)
	$(EXE)/./testAVL

$(OBJ)/testAVL.o: $(SRC)/testAVL.cpp $(INC)/AVLTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testAVL.cpp -o $@


# Command: make InvertTree
# Invert a Binary Search Tree
InvertTreeObjs := $(OBJ)/InvertTree.o 

InvertTree: $(InvertTreeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InvertTree $(InvertTreeObjs)
	$(EXE)/./InvertTree

$(OBJ)/InvertTree.o: $(SRC)/InvertTree.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InvertTree.cpp -o $@



# Command: make kThSmallest
# Find the Kth Smallest element in a BST
kThSmallestObjs := $(OBJ)/kThSmallest.o 

kThSmallest: $(kThSmallestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/kThSmallest $(kThSmallestObjs)
	$(EXE)/./kThSmallest

$(OBJ)/kThSmallest.o: $(SRC)/kThSmallest.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/kThSmallest.cpp -o $@



# Command: make ValidBST
# Check if a Binary Tree is a Valid Binary Search Tree
ValidBSTObjs := $(OBJ)/ValidBST.o 

ValidBST: $(ValidBSTObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ValidBST $(ValidBSTObjs)
	$(EXE)/./ValidBST

$(OBJ)/ValidBST.o: $(SRC)/ValidBST.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/ValidBST.cpp -o $@	



# Make all
all: InvertTree kThSmallest ValidBST


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*