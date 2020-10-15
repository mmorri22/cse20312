# This is the Makefile for the CSE 20312 course - Lecture 31

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


# Command: make testRBTNode1
# Test initial class for compilation
testRBTree1Objs := $(OBJ)/testRBTree1.o

testRBTree1: $(testRBTree1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree1 $(testRBTree1Objs)
	$(EXE)/./testRBTree1

$(OBJ)/testRBTree1.o: $(SRC)/testRBTree1.cpp $(INC)/RBTree1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree1.cpp -o $@



# Command: make testRBTNode2
# Test initial class for compilation
testRBTree2Objs := $(OBJ)/testRBTree2.o

testRBTree2: $(testRBTree2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree2 $(testRBTree2Objs)
	$(EXE)/./testRBTree2

$(OBJ)/testRBTree2.o: $(SRC)/testRBTree2.cpp $(INC)/RBTree2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree2.cpp -o $@	



# Command: make RBDelTest
# Shows a successful RBTree Tree Test
RBDelTestObjs := $(OBJ)/RBDelTest.o

RBDelTest: $(RBDelTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBDelTest $(RBDelTestObjs)
	$(EXE)/./RBDelTest

$(OBJ)/RBDelTest.o: $(SRC)/RBDelTest.cpp $(INC)/RBTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/RBDelTest.cpp -o $@


# Command: make treeTest
# Shows a successful RBTree Tree Test
treeTestObjs := $(OBJ)/treeTest.o

treeTest: $(treeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/treeTest $(treeTestObjs)
	$(EXE)/./treeTest

$(OBJ)/treeTest.o: $(SRC)/treeTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/treeTest.cpp -o $@



# Command: make multiSet
# Shows a successful RBTree Tree Test
multiSetObjs := $(OBJ)/multiSet.o

multiSet: $(multiSetObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/multiSet $(multiSetObjs)
	$(EXE)/./multiSet

$(OBJ)/multiSet.o: $(SRC)/multiSet.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/multiSet.cpp -o $@
	

# Make all
all: testRBTNode1Objs testRBTNode2Objs RBDelTest treeTest multiSet

# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
