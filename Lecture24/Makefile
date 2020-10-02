# This is the Makefile for the CSE 20312 course - Lecture 25

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



# Command: make testBST5
# Test Level Order Traversal
testBST5Objs := $(OBJ)/testBST5.o 

testBST5: $(testBST5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST5 $(testBST5Objs)
	$(EXE)/./testBST5

$(OBJ)/testBST5.o: $(SRC)/testBST5.cpp $(INC)/BST6.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST5.cpp -o $@
	


# Command: make testBST6
# Test Contains, Min, and Max
testBST6Objs := $(OBJ)/testBST6.o 

testBST6: $(testBST6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST6 $(testBST6Objs)
	$(EXE)/./testBST6

$(OBJ)/testBST6.o: $(SRC)/testBST6.cpp $(INC)/BST6.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST6.cpp -o $@



# Command: make testBST7
# Test Delete 
testBST7Objs := $(OBJ)/testBST7.o 

testBST7: $(testBST7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBST7 $(testBST7Objs)
	$(EXE)/./testBST7

$(OBJ)/testBST7.o: $(SRC)/testBST7.cpp $(INC)/BST7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBST7.cpp -o $@



# Command: make maxHeight
# Test Max Height 
maxHeightObjs := $(OBJ)/maxHeight.o 

maxHeight: $(maxHeightObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxHeight $(maxHeightObjs)
	$(EXE)/./maxHeight

$(OBJ)/maxHeight.o: $(SRC)/maxHeight.cpp $(INC)/BST7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxHeight.cpp -o $@
	
	
# Command: make testAVL1
# Test AVL Tree - 1
testAVL1Objs := $(OBJ)/testAVL1.o 

testAVL1: $(testAVL1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testAVL1 $(testAVL1Objs)
	$(EXE)/./testAVL1

$(OBJ)/testAVL1.o: $(SRC)/testAVL1.cpp $(INC)/AVLTree1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testAVL1.cpp -o $@



# Command: make testAVL
# Test AVL Tree - With Full Balance
testAVLObjs := $(OBJ)/testAVL.o 

testAVL: $(testAVLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testAVL $(testAVLObjs)
	$(EXE)/./testAVL

$(OBJ)/testAVL.o: $(SRC)/testAVL.cpp $(INC)/AVLTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testAVL.cpp -o $@
	

# Make all
all: testBSTNode1 testBSTNode2


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*