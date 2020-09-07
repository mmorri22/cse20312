# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lab 04

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# LeetCode Insert Interval Problem
# Command: make InsertInt
InsertIntObjs := $(OBJ)/InsertInt.o

InsertInt: $(InsertIntObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertInt $(InsertIntObjs)
	$(EXE)/./InsertInt

$(OBJ)/InsertInt.o: $(SRC)/InsertInt.cpp $(INC)/Lab04.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertInt.cpp -o $@




# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	


# Make all
all: InsertInt

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
