# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lecture 15

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make findCircular
# Solution to Problem 3 from Lecture 20
findCircularObjs :=  $(OBJ)/findCircular.o

findCircular: $(findCircularObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/findCircular $(findCircularObjs)
	$(EXE)/./findCircular

$(OBJ)/findCircular.o: $(SRC)/findCircular.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/findCircular.cpp -o $@
	
	
	
# Command: make findCircular2
# Solution to Problem 3 from Lecture 20
findCircular2Objs :=  $(OBJ)/findCircular2.o

findCircular2: $(findCircular2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/findCircular2 $(findCircular2Objs)
	$(EXE)/./findCircular2

$(OBJ)/findCircular2.o: $(SRC)/findCircular2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/findCircular2.cpp -o $@


# Command: make reorderList
reorderListObjs :=  $(OBJ)/reorderList.o

reorderList: $(reorderListObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/reorderList $(reorderListObjs)
	$(EXE)/./reorderList

$(OBJ)/reorderList.o: $(SRC)/reorderList.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/reorderList.cpp -o $@

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir obj exe


# Make all
all: findCircular findCircular2 reorderList

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
