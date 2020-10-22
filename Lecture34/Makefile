# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 30

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


# Command: make SplayTest
# Shows a successful Splay Tree Test
SplayTestObjs := $(OBJ)/SplayTest.o

SplayTest: $(SplayTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SplayTest $(SplayTestObjs)
	$(EXE)/./SplayTest

$(OBJ)/SplayTest.o: $(SRC)/SplayTest.cpp $(INC)/SplayTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SplayTest.cpp -o $@



# Command: make CacheExample
# Shows a SplayTree accessing memory locations
CacheExampleObjs := $(OBJ)/CacheExample.o

CacheExample: $(CacheExampleObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/CacheExample $(CacheExampleObjs)
	$(EXE)/./CacheExample

$(OBJ)/CacheExample.o: $(SRC)/CacheExample.cpp $(INC)/SplayTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/CacheExample.cpp -o $@



# Make all
all: SplayTest


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
	
	
# Make gitPre
gitPre:
	make clean
	git add Makefile $(INC)/* $(SRC)/*
	git commit -m "Lecture 24 Preview Assignment"
	git push

	
# Make gitIn
gitIn:
	make clean
	git add Makefile $(INC)/* $(SRC)/*
	git commit -m "Lecture 24 In Class"
	git push
	
	
# Make gitIn
gitFix:
	make clean
	git add --all
	git commit -m "Lecture 24 In Class - Fix"
	git push
