# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lecture 11

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


# Command: make fibOld
fibOldObjs := $(OBJ)/fibOld.o

fibOld: $(fibOldObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/fibOld $(fibOldObjs)

$(OBJ)/fibOld.o: $(SRC)/fibOld.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/fibOld.cpp -o $@
	
	
# Command: make fibMemo
fibMemoObjs := $(OBJ)/fibMemo.o

fibMemo: $(fibMemoObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/fibMemo $(fibMemoObjs)

$(OBJ)/fibMemo.o: $(SRC)/fibMemo.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/fibMemo.cpp -o $@



# Command: make steps
stepsObjs := $(OBJ)/steps.o

steps: $(stepsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/steps $(stepsObjs)

$(OBJ)/steps.o: $(SRC)/steps.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/steps.cpp -o $@



# Command: make coinChange
coinChangeObjs := $(OBJ)/coinChange.o

coinChange: $(coinChangeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/coinChange $(coinChangeObjs)

$(OBJ)/coinChange.o: $(SRC)/coinChange.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/coinChange.cpp -o $@



# Command: make coinChange1
coinChange1Objs := $(OBJ)/coinChange1.o

coinChange1: $(coinChange1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/coinChange1 $(coinChange1Objs)

$(OBJ)/coinChange1.o: $(SRC)/coinChange1.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/coinChange1.cpp -o $@



# Command: make coinChange2
coinChange2Objs := $(OBJ)/coinChange2.o

coinChange2: $(coinChange2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/coinChange2 $(coinChange2Objs)

$(OBJ)/coinChange2.o: $(SRC)/coinChange2.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/coinChange2.cpp -o $@



# Command: make coinChange3
coinChange3Objs := $(OBJ)/coinChange3.o

coinChange3: $(coinChange3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/coinChange3 $(coinChange3Objs)

$(OBJ)/coinChange3.o: $(SRC)/coinChange3.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/coinChange3.cpp -o $@



# Command: make coinChange4
coinChange4Objs := $(OBJ)/coinChange4.o

coinChange4: $(coinChange4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/coinChange4 $(coinChange4Objs)

$(OBJ)/coinChange4.o: $(SRC)/coinChange4.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/coinChange4.cpp -o $@
	

# Make all
all: fibOld fibMemo steps


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
