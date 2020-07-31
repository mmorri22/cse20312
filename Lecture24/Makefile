# This is the Makefile for the CSE 20312 course - Lecture 24

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


	
# Command: make testBSTNode1
# Initial Examples of BSTNode
testBSTNode1Objs := $(OBJ)/testBSTNode1.o 

testBSTNode1: $(testBSTNode1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBSTNode1 $(testBSTNode1Objs)
	$(EXE)/./testBSTNode1

$(OBJ)/testBSTNode1.o: $(SRC)/testBSTNode1.cpp $(INC)/BSTNode1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBSTNode1.cpp -o $@



# Command: make testBSTNode2
# Initial Examples of BSTNode with pointers
# Deliberate Compiler Error
testBSTNode2Objs := $(OBJ)/testBSTNode2.o 

testBSTNode2: $(testBSTNode2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBSTNode2 $(testBSTNode2Objs)
	$(EXE)/./testBSTNode2

$(OBJ)/testBSTNode2.o: $(SRC)/testBSTNode2.cpp $(INC)/BSTNode2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBSTNode2.cpp -o $@



# Command: make testBST1
# Initial Examples of BST with pointers
# Deliberate Compiler Error
testBST1Objs := $(OBJ)/testBST1.o 

testBST1: $(testBST1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST1 $(testBST1Objs)
	$(EXE)/./testBST1

$(OBJ)/testBST1.o: $(SRC)/testBST1.cpp $(INC)/BST1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST1.cpp -o $@


# Command: make testBST2Bad
# Shows the student that pointers need to be 
# called by reference
testBST2BadObjs := $(OBJ)/testBST2Bad.o 

testBST2Bad: $(testBST2BadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST2Bad $(testBST2BadObjs)
	$(EXE)/./testBST2Bad

$(OBJ)/testBST2Bad.o: $(SRC)/testBST2Bad.cpp $(INC)/BST2Bad.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST2Bad.cpp -o $@


# Command: make testBST2
# Initial Examples of BST with pointers
testBST2Objs := $(OBJ)/testBST2.o 

testBST2: $(testBST2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST2 $(testBST2Objs)
	$(EXE)/./testBST2

$(OBJ)/testBST2.o: $(SRC)/testBST2.cpp $(INC)/BST2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST2.cpp -o $@


# Command: make testBST3
# Prints Pre-Order with the In-Order
testBST3Objs := $(OBJ)/testBST3.o 

testBST3: $(testBST3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST3 $(testBST3Objs)
	$(EXE)/./testBST3

$(OBJ)/testBST3.o: $(SRC)/testBST3.cpp $(INC)/BST3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST3.cpp -o $@	



# Command: make testBST4
# Prints Pre-Order with the In-Order
testBST4Objs := $(OBJ)/testBST4.o 

testBST4: $(testBST4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST4 $(testBST4Objs)
	$(EXE)/./testBST4

$(OBJ)/testBST4.o: $(SRC)/testBST4.cpp $(INC)/BST4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST4.cpp -o $@
	
	
# Command: make testBST5
# Prints Pre-Order with the In-Order
testBST5Objs := $(OBJ)/testBST5.o 

testBST5: $(testBST5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST5 $(testBST5Objs)
	$(EXE)/./testBST5

$(OBJ)/testBST5.o: $(SRC)/testBST5.cpp $(INC)/BST5.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST5.cpp -o $@
	

# Make all
all: testBSTNode1 testBSTNode2


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*