# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 Optional Lecture 05

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



# Command: make Courses
CoursesObjs :=  $(OBJ)/Courses.o

Courses: $(CoursesObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Courses $(CoursesObjs)
	$(EXE)/./Courses

$(OBJ)/Courses.o: $(SRC)/Courses.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Courses.cpp -o $@



# Command: make LongConSeq
LongConSeqObjs :=  $(OBJ)/LongConSeq.o

LongConSeq: $(LongConSeqObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LongConSeq $(LongConSeqObjs)
	$(EXE)/./LongConSeq

$(OBJ)/LongConSeq.o: $(SRC)/LongConSeq.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/LongConSeq.cpp -o $@



# Make all
all: Courses LongConSeq

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
	
	
	
# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)
	
	

