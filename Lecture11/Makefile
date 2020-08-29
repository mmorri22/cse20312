# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 24312 - Lecture 08 - Part 2

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


# Command: make IrishTest
# Base class for First Inheritance Example
IrishTestObjs := $(OBJ)/IrishTest.o $(OBJ)/Irish.o 

IrishTest: $(IrishTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/IrishTest $(IrishTestObjs)
	$(EXE)/./IrishTest

$(OBJ)/IrishTest.o: $(SRC)/IrishTest.cpp $(INC)/Irish.h
	$(PP) $(CXXFLAGS) -c $(SRC)/IrishTest.cpp -o $@

$(OBJ)/Irish.o: $(INC)/Irish.cpp $(INC)/Irish.h
	$(PP) $(CXXFLAGS) -c $(INC)/Irish.cpp -o $@



# Command: make Inherit 
# Derived Classes for First Inheritance Example 
InheritObjs := $(OBJ)/Inherit.o $(OBJ)/Faculty.o $(OBJ)/Student.o $(OBJ)/Irish.o

Inherit: $(InheritObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Inherit $(InheritObjs)
	$(EXE)/./Inherit

# Inherit.cpp class both derived classes
$(OBJ)/Inherit.o: $(SRC)/Inherit.cpp $(INC)/Student.h $(INC)/Faculty.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Inherit.cpp -o $@

# Faculty inherits Irish
$(OBJ)/Faculty.o: $(INC)/Faculty.cpp $(INC)/Faculty.h $(INC)/Irish.h
	$(PP) $(CXXFLAGS) -c $(INC)/Faculty.cpp -o $@

# Student inherits Irish
$(OBJ)/Student.o: $(INC)/Student.cpp $(INC)/Student.h $(INC)/Irish.h
	$(PP) $(CXXFLAGS) -c $(INC)/Student.cpp -o $@

# Irish.o is already created in the Base Class
	


# Command: make Inherit2
# Example of this object in Inheritance Example 
Inherit2Objs := $(OBJ)/Inherit2.o $(OBJ)/Faculty.o $(OBJ)/Student.o $(OBJ)/Irish.o

Inherit2: $(Inherit2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Inherit2 $(Inherit2Objs)
	$(EXE)/./Inherit2

# Inherit.cpp class both derived classes
$(OBJ)/Inherit2.o: $(SRC)/Inherit2.cpp $(INC)/Student.h $(INC)/Faculty.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Inherit2.cpp -o $@

# Irish.o, Student.o, and Faculty.o are already created in make Inherit
	

# Make all
all: IrishTest Inherit Inherit2


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
