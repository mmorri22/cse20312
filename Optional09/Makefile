# This is the Makefile for the CSE 20312 course - Optional Lecture 09

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
	
	
	
# Command: make testMinHeap
ValidParenObjs := $(OBJ)/ValidParen.o $(OBJ)/balanced.o

ValidParen: $(ValidParenObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ValidParen $(ValidParenObjs)

$(OBJ)/ValidParen.o: $(SRC)/ValidParen.cpp $(INC)/balanced.h
	$(PP) $(CXXFLAGS) -c $(SRC)/ValidParen.cpp -o $@

$(OBJ)/balanced.o: $(INC)/balanced.cpp $(INC)/balanced.h
	$(PP) $(CXXFLAGS) -c $(INC)/balanced.cpp -o $@


# Command: make SubNoRepeat
SubNoRepeatObjs := $(OBJ)/SubNoRepeat.o

SubNoRepeat: $(SubNoRepeatObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SubNoRepeat $(SubNoRepeatObjs)

$(OBJ)/SubNoRepeat.o: $(SRC)/SubNoRepeat.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SubNoRepeat.cpp -o $@
	
	
# Make all
all: ValidParen SubNoRepeat



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
