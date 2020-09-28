# This is the Makefile for the CSE 20312 course Lecture 22

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



# Command: make Alien
AlienObjs := $(OBJ)/Alien.o 

Alien: $(AlienObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Alien $(AlienObjs)
	$(EXE)/./Alien

$(OBJ)/Alien.o: $(SRC)/Alien.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Alien.cpp -o $@

	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make all
all: Alien


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
