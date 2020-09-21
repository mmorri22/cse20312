# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lab 05

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
# Command: make hanoi
hanoiObjs := $(OBJ)/hanoi.o

hanoi: $(hanoiObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/hanoi $(hanoiObjs)

$(OBJ)/hanoi.o: $(SRC)/hanoi.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/hanoi.cpp -o $@




# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	


# Make all
all: InsertInt

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
