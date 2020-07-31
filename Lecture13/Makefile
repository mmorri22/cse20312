# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lecture 13

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make SLLTest
SLLTestObjs := $(OBJ)/SLLTest.o

SLLTest: $(SLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SLLTest $(SLLTestObjs)

$(OBJ)/SLLTest.o: $(SRC)/SLLTest.cpp $(INC)/SLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SLLTest.cpp -o $@



# Command: make SLLTest2
SLLTest2Objs := $(OBJ)/SLLTest2.o

SLLTest2: $(SLLTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SLLTest2 $(SLLTest2Objs)
	$(EXE)/./SLLTest2

$(OBJ)/SLLTest2.o: $(SRC)/SLLTest2.cpp $(INC)/SLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SLLTest2.cpp -o $@

	

# Make all
all: countSort1 countSort1


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
