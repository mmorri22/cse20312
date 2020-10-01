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


# Command: make MaxPathSum
# Calculated the Max Path Sum of a BST
MaxPathSumObjs := $(OBJ)/MaxPathSum.o 

MaxPathSum: $(MaxPathSumObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MaxPathSum $(MaxPathSumObjs)
	$(EXE)/./MaxPathSum

$(OBJ)/MaxPathSum.o: $(SRC)/MaxPathSum.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MaxPathSum.cpp -o $@



# Command: make SubTree
# Calculated the Max Path Sum of a BST
SubTreeObjs := $(OBJ)/SubTree.o 

SubTree: $(SubTreeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SubTree $(SubTreeObjs)
	$(EXE)/./SubTree

$(OBJ)/SubTree.o: $(SRC)/SubTree.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SubTree.cpp -o $@
	

# Make all
all: MaxPathSum SubTree


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*