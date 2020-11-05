# This is the Makefile for the CSE 20312 course - Optional Lecture 10

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
MinSortArrayObjs := $(OBJ)/MinSortArray.o

MinSortArray: $(MinSortArrayObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MinSortArray $(MinSortArrayObjs)

$(OBJ)/MinSortArray.o: $(SRC)/MinSortArray.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MinSortArray.cpp -o $@


# Command: make SubNoRepeat
SubNoRepeatObjs := $(OBJ)/SubNoRepeat.o

SubNoRepeat: $(SubNoRepeatObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SubNoRepeat $(SubNoRepeatObjs)

$(OBJ)/SubNoRepeat.o: $(SRC)/SubNoRepeat.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SubNoRepeat.cpp -o $@
	
	
# Make all
all: MinSortArray SubNoRepeat



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
