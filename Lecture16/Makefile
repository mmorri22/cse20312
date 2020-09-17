# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lecture 15

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


# Command: make inigo
# std::list example
inigoObjs :=  $(OBJ)/inigo.o

inigo: $(inigoObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/inigo $(inigoObjs)
	$(EXE)/./inigo

$(OBJ)/inigo.o: $(SRC)/inigo.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/inigo.cpp -o $@	


# Command: make RemoveDups
# Solution to Problem 1 from Lecture 20
RemoveDupsObjs :=  $(OBJ)/RemoveDups.o

RemoveDups: $(RemoveDupsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RemoveDups $(RemoveDupsObjs)
	$(EXE)/./RemoveDups 10 22 18 22 15 18 22 10 96 8
	$(EXE)/./RemoveDups 10 25 12 44 22 106

$(OBJ)/RemoveDups.o: $(SRC)/RemoveDups.cpp $(INC)/DLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/RemoveDups.cpp -o $@
	


# Command: make nthToLast
# Solution to Problem 2 from Lecture 20
nthToLastObjs :=  $(OBJ)/nthToLast.o

nthToLast: $(nthToLastObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/nthToLast $(nthToLastObjs)
	$(EXE)/./nthToLast 10 18 22 24 31 9 18
	$(EXE)/./nthToLast 10 18 22
	$(EXE)/./nthToLast 10 18
	$(EXE)/./nthToLast

$(OBJ)/nthToLast.o: $(SRC)/nthToLast.cpp $(INC)/SLList.h
	$(PP) $(CXXFLAGS) -c $(SRC)/nthToLast.cpp -o $@	
	


# Command: make findCircular
# Solution to Problem 3 from Lecture 20
findCircularObjs :=  $(OBJ)/findCircular.o

findCircular: $(findCircularObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/findCircular $(findCircularObjs)
	$(EXE)/./findCircular

$(OBJ)/findCircular.o: $(SRC)/findCircular.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/findCircular.cpp -o $@
	
	
	
# Command: make findCircular2
# Solution to Problem 3 from Lecture 20
findCircular2Objs :=  $(OBJ)/findCircular2.o

findCircular2: $(findCircular2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/findCircular2 $(findCircular2Objs)
	$(EXE)/./findCircular2

$(OBJ)/findCircular2.o: $(SRC)/findCircular2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/findCircular2.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables	


# Make all
all: RemoveDups nthToLast findCircular findCircular2

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
