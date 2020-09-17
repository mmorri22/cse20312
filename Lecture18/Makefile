# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lecture 18

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


# Command: make wrapper
wrapperQueueObjs :=  $(OBJ)/wrapperQueue.o

wrapperQueue: $(wrapperQueueObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/wrapperQueue $(wrapperQueueObjs)
	$(EXE)/./wrapperQueue

$(OBJ)/wrapperQueue.o: $(SRC)/wrapperQueue.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/wrapperQueue.cpp -o $@
	

# Command: make wrapperStack
wrapperStackObjs :=  $(OBJ)/wrapperStack.o

wrapperStack: $(wrapperStackObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/wrapperStack $(wrapperStackObjs)
	$(EXE)/./wrapperStack

$(OBJ)/wrapperStack.o: $(SRC)/wrapperStack.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/wrapperStack.cpp -o $@
	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)	


# Make all
all: wrapperQueue wrapperStack

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
