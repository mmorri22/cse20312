# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lecture 12

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


# Command: make countSort1
countSort1Objs := $(OBJ)/countSort1.o

countSort1: $(countSort1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSort1 $(countSort1Objs)
	$(EXE)/./countSort1

$(OBJ)/countSort1.o: $(SRC)/countSort1.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSort1.cpp -o $@



# Command: make countSort2
countSort2Objs := $(OBJ)/countSort2.o

countSort2: $(countSort2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSort2 $(countSort2Objs)
	$(EXE)/./countSort2

$(OBJ)/countSort2.o: $(SRC)/countSort2.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSort2.cpp -o $@
	

# Command: make countSort3
countSort3Objs := $(OBJ)/countSort3.o

countSort3: $(countSort3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSort3 $(countSort3Objs)
	$(EXE)/./countSort3

$(OBJ)/countSort3.o: $(SRC)/countSort3.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSort3.cpp -o $@
	

# Command: make countSort
countSortObjs := $(OBJ)/countSort.o

countSort: $(countSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSort $(countSortObjs)
	$(EXE)/./countSort

$(OBJ)/countSort.o: $(SRC)/countSort.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSort.cpp -o $@



# Command: make countSortImpr1
countSortImpr1Objs := $(OBJ)/countSortImpr1.o

countSortImpr1: $(countSortImpr1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSortImpr1 $(countSortImpr1Objs)
	$(EXE)/./countSortImpr1

$(OBJ)/countSortImpr1.o: $(SRC)/countSortImpr1.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSortImpr1.cpp -o $@



# Command: make countSortImpr2
countSortImpr2Objs := $(OBJ)/countSortImpr2.o

countSortImpr2: $(countSortImpr2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSortImpr2 $(countSortImpr2Objs)
	$(EXE)/./countSortImpr2

$(OBJ)/countSortImpr2.o: $(SRC)/countSortImpr2.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSortImpr2.cpp -o $@



# Command: make countSortImpr
countSortImprObjs := $(OBJ)/countSortImpr.o

countSortImpr: $(countSortImprObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSortImpr $(countSortImprObjs)
	$(EXE)/./countSortImpr

$(OBJ)/countSortImpr.o: $(SRC)/countSortImpr.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSortImpr.cpp -o $@



# Command: make countSortSTL
countSortSTLObjs := $(OBJ)/countSortSTL.o

countSortSTL: $(countSortSTLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSortSTL $(countSortSTLObjs)
	$(EXE)/./countSortSTL

$(OBJ)/countSortSTL.o: $(SRC)/countSortSTL.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/countSortSTL.cpp -o $@



# Command: make sepChain
sepChainObjs := $(OBJ)/sepChain.o

sepChain: $(sepChainObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sepChain $(sepChainObjs)
	$(EXE)/./sepChain

$(OBJ)/sepChain.o: $(SRC)/sepChain.cpp $(INC)/DynArr.h $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/sepChain.cpp -o $@



# Command: make bucketSort
bucketSortObjs := $(OBJ)/bucketSort.o

bucketSort: $(bucketSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/bucketSort $(bucketSortObjs)
	$(EXE)/./bucketSort

$(OBJ)/bucketSort.o: $(SRC)/bucketSort.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/bucketSort.cpp -o $@
	

# Make all
all: countSort1 countSort1


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
