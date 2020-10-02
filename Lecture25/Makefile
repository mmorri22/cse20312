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


# Command: make InvertTree
# Invert a Binary Search Tree
InvertTreeObjs := $(OBJ)/InvertTree.o 

InvertTree: $(InvertTreeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InvertTree $(InvertTreeObjs)
	$(EXE)/./InvertTree

$(OBJ)/InvertTree.o: $(SRC)/InvertTree.cpp $(INC)/BST.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InvertTree.cpp -o $@


	

# Make all
all: InvertTree


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*