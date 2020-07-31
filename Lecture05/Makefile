# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 24312 course Lecture 05 - Part 2

# G++ is for the GCC compiler for C++
PP := g++

# Original Compiler Flags brought back for tempVoidNode only 
OLDFLAGS := -O0 -g -Wall
OLDCXXFLAGS := -m64 -std=c++11 $(OLDFLAGS)

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make tempVoidNode
# Shows allocating templated generic types on the heap
# using imperative and procedural programming

tempVoidNodeObjs := $(OBJ)/tempVoidNode.o

tempVoidNode: $(tempVoidNodeObjs)
	$(PP) $(OLDCXXFLAGS) -o $(EXE)/tempVoidNode $(tempVoidNodeObjs)
	$(EXE)/./tempVoidNode

$(OBJ)/tempVoidNode.o: $(SRC)/tempVoidNode.cpp
	$(PP) $(OLDCXXFLAGS) -c $(SRC)/tempVoidNode.cpp -o $@



# Command: make tempVoidNode2
# Shows allocating templated generic types on the heap
# using imperative and procedural programming
# Uses proper casting of float

tempVoidNode2Objs := $(OBJ)/tempVoidNode2.o

tempVoidNode2: $(tempVoidNode2Objs)
	$(PP) $(OLDCXXFLAGS) -o $(EXE)/tempVoidNode2 $(tempVoidNode2Objs)
	$(EXE)/./tempVoidNode2

$(OBJ)/tempVoidNode2.o: $(SRC)/tempVoidNode2.cpp
	$(PP) $(OLDCXXFLAGS) -c $(SRC)/tempVoidNode2.cpp -o $@



# Command: make template1
# Simple templated class example

template1Objs := $(OBJ)/template1.o

template1: $(template1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/template1 $(template1Objs)
	$(EXE)/./template1

$(OBJ)/template1.o: $(SRC)/template1.cpp $(INC)/A_1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/template1.cpp -o $@
	

# Command: make tempTest
# Simple templated class example

tempTestObjs := $(OBJ)/tempTest.o

tempTest: $(tempTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempTest $(tempTestObjs)
	$(EXE)/./tempTest


$(OBJ)/tempTest.o: $(SRC)/tempTest.cpp $(INC)/A.h
	$(PP) $(CXXFLAGS) -c $(SRC)/tempTest.cpp -o $@


	

# Command: make classBad
# Example of Pitfall of splitting templated classes into cpp and h
# Contains deliberate compiler errors

classBadObjs := $(OBJ)/classBad.o $(OBJ)/Abad.o

classBad: $(classBadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/classBad $(classBadObjs)
	$(EXE)/./classBad

$(OBJ)/classBad.o: $(SRC)/classBad.cpp $(INC)/Abad.h
	$(PP) $(CXXFLAGS) -c $(SRC)/classBad.cpp -o $@
	
$(OBJ)/Abad.o: $(INC)/Abad.cpp $(INC)/Abad.h
	$(PP) $(CXXFLAGS) -c $(INC)/Abad.cpp -o $@
	
	
	
# Command: make tempBad
# Example of Pitfall of splitting bad templating
# Contains deliberate compiler errors

tempBadObjs := $(OBJ)/tempBad.o

tempBad: $(tempBadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempBad $(tempBadObjs)
	$(EXE)/./tempBad

$(OBJ)/tempBad.o: $(SRC)/tempBad.cpp $(INC)/A.h
	$(PP) $(CXXFLAGS) -c $(SRC)/tempBad.cpp -o $@
	
	


# Command: make DynArrTest
# Initial Abstract Data Type class

DynArrTestObjs := $(OBJ)/DynArrTest.o

DynArrTest: $(DynArrTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DynArrTest $(DynArrTestObjs)

$(OBJ)/DynArrTest.o: $(SRC)/DynArrTest.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DynArrTest.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: tempDest DynArrTest

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
