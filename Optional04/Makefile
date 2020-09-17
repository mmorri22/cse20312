# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 19

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



# Command: make DLLMerge
# In-Class DLLMerge problem
DLLMergeObjs :=  $(OBJ)/DLLMerge.o

DLLMerge: $(DLLMergeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLMerge $(DLLMergeObjs)
	$(EXE)/./DLLMerge

$(OBJ)/DLLMerge.o: $(SRC)/DLLMerge.cpp $(INC)/DLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DLLMerge.cpp -o $@


# Command: make DLLMergeSort
# In-Class DLLMergeSort problem
DLLMergeSortObjs :=  $(OBJ)/DLLMergeSort.o

DLLMergeSort: $(DLLMergeSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLMergeSort $(DLLMergeSortObjs)
	$(EXE)/./DLLMergeSort

$(OBJ)/DLLMergeSort.o: $(SRC)/DLLMergeSort.cpp $(INC)/DLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DLLMergeSort.cpp -o $@


# Make all
all: DLLMerge DLLMergeSort

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
	
	
	
# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)
	
	

