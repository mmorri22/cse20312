# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lecture 14

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folder
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make DLLTest
# Doubly Linked List Class Example with int
DLLTestObjs :=  $(OBJ)/DLLTest.o

DLLTest: $(DLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLTest $(DLLTestObjs)
	$(EXE)/./DLLTest 10 25 12 10 44 88

$(OBJ)/DLLTest.o: $(SRC)/DLLTest.cpp $(INC)/DLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DLLTest.cpp -o $@
	
	
	
# Command: make DLLTest2
# Doubly Linked List Class Example with std::string
DLLTest2Objs :=  $(OBJ)/DLLTest2.o

DLLTest2: $(DLLTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLTest2 $(DLLTest2Objs)
	$(EXE)/./DLLTest2

$(OBJ)/DLLTest2.o: $(SRC)/DLLTest2.cpp $(INC)/DLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DLLTest2.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables


# Make all
all: DLLTest DLLTest2

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
