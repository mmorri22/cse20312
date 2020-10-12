# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 28

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


# Command: make BTreeInClass
# Shows a successful BTree Tree Test
BTreeInClassObjs := $(OBJ)/BTreeInClass.o

BTreeInClass: $(BTreeInClassObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BTreeInClass $(BTreeInClassObjs)
	$(EXE)/./BTreeInClass

$(OBJ)/BTreeInClass.o: $(SRC)/BTreeInClass.cpp $(INC)/BTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/BTreeInClass.cpp -o $@
	

# Command: make BTreeTest
# Shows a successful BTree Tree Test
BTreeTestObjs := $(OBJ)/BTreeTest.o

BTreeTest: $(BTreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BTreeTest $(BTreeTestObjs)
	$(EXE)/./BTreeTest

$(OBJ)/BTreeTest.o: $(SRC)/BTreeTest.cpp $(INC)/BTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/BTreeTest.cpp -o $@



# Make all
all: BTreeTest


# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*