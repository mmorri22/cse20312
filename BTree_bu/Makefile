# This is the Makefile for the CSE 24312 course - Lecture 28

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make testBTreeNode1
testBTreeNode1Objs := $(OBJ)/testBTreeNode1.o

testBTreeNode1: $(testBTreeNode1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode1 $(testBTreeNode1Objs)
	$(EXE)/./testBTreeNode1

$(OBJ)/testBTreeNode1.o: $(SRC)/testBTreeNode1.cpp $(INC)/BTreeNode1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode1.cpp -o $@



# Command: make testBTreeNode1Bad
testBTreeNode1BadObjs := $(OBJ)/testBTreeNode1Bad.o

testBTreeNode1Bad: $(testBTreeNode1BadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode1Bad $(testBTreeNode1BadObjs)
	$(EXE)/./testBTreeNode1Bad

$(OBJ)/testBTreeNode1Bad.o: $(SRC)/testBTreeNode1Bad.cpp $(INC)/BTreeNode1Bad.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode1Bad.cpp -o $@



# Command: make testBTreeNode2
testBTreeNode2Objs := $(OBJ)/testBTreeNode2.o

testBTreeNode2: $(testBTreeNode2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode2 $(testBTreeNode2Objs)
	$(EXE)/./testBTreeNode2

$(OBJ)/testBTreeNode2.o: $(SRC)/testBTreeNode2.cpp $(INC)/BTreeNode2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode2.cpp -o $@
	


# Command: make testBTreeNode3Odd
testBTreeNode3OddObjs := $(OBJ)/testBTreeNode3Odd.o

testBTreeNode3Odd: $(testBTreeNode3OddObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode3Odd $(testBTreeNode3OddObjs)
	$(EXE)/./testBTreeNode3Odd

$(OBJ)/testBTreeNode3Odd.o: $(SRC)/testBTreeNode3Odd.cpp $(INC)/BTreeNode3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode3Odd.cpp -o $@



# Command: make testBTreeNode3Even
testBTreeNode3EvenObjs := $(OBJ)/testBTreeNode3Even.o

testBTreeNode3Even: $(testBTreeNode3EvenObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode3Even $(testBTreeNode3EvenObjs)
	$(EXE)/./testBTreeNode3Even

$(OBJ)/testBTreeNode3Even.o: $(SRC)/testBTreeNode3Even.cpp $(INC)/BTreeNode3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode3Even.cpp -o $@



# Command: make testBTreeNode4
testBTreeNode4Objs := $(OBJ)/testBTreeNode4.o

testBTreeNode4: $(testBTreeNode4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTreeNode4 $(testBTreeNode4Objs)
	$(EXE)/./testBTreeNode4

$(OBJ)/testBTreeNode4.o: $(SRC)/testBTreeNode4.cpp $(INC)/BTreeNode4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTreeNode4.cpp -o $@	
	
	
	
# Command: make testBTree
testBTree1Objs := $(OBJ)/testBTree1.o

testBTree1: $(testBTree1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree1 $(testBTree1Objs)
	$(EXE)/./testBTree1

$(OBJ)/testBTree1.o: $(SRC)/testBTree1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree1.cpp -o $@


# Command: make testBTree2
testBTree2Objs := $(OBJ)/testBTree2.o

testBTree2: $(testBTree2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree2 $(testBTree2Objs)
	$(EXE)/./testBTree2

$(OBJ)/testBTree2.o: $(SRC)/testBTree2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree2.cpp -o $@



# Command: make testBTree3
testBTree3Objs := $(OBJ)/testBTree3.o

testBTree3: $(testBTree3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree3 $(testBTree3Objs)
	$(EXE)/./testBTree3

$(OBJ)/testBTree3.o: $(SRC)/testBTree3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree3.cpp -o $@



# Command: make testBTree4
testBTree4Objs := $(OBJ)/testBTree4.o

testBTree4: $(testBTree4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree4 $(testBTree4Objs)
	$(EXE)/./testBTree4

$(OBJ)/testBTree4.o: $(SRC)/testBTree4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree4.cpp -o $@



# Command: make testBTree5
testBTree5Objs := $(OBJ)/testBTree5.o

testBTree5: $(testBTree5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree5 $(testBTree5Objs)
	$(EXE)/./testBTree5

$(OBJ)/testBTree5.o: $(SRC)/testBTree5.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree5.cpp -o $@
	
	
	
# Command: make testBTree6
testBTree6Objs := $(OBJ)/testBTree6.o

testBTree6: $(testBTree6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree6 $(testBTree6Objs)
	$(EXE)/./testBTree6

$(OBJ)/testBTree6.o: $(SRC)/testBTree6.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree6.cpp -o $@
	
	
	
# Command: make testBTree7
testBTree7Objs := $(OBJ)/testBTree7.o

testBTree7: $(testBTree7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree7 $(testBTree7Objs)
	$(EXE)/./testBTree7

$(OBJ)/testBTree7.o: $(SRC)/testBTree7.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree7.cpp -o $@


# Command: make testBTree
testBTreeObjs := $(OBJ)/testBTree.o

testBTree: $(testBTreeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree $(testBTreeObjs)
	$(EXE)/./testBTree

$(OBJ)/testBTree.o: $(SRC)/testBTree.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree.cpp -o $@


# Command: make testBTree7Str
testBTree7StrObjs := $(OBJ)/testBTree7Str.o

testBTree7Str: $(testBTree7StrObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBTree7Str $(testBTree7StrObjs)
	$(EXE)/./testBTree7Str

$(OBJ)/testBTree7Str.o: $(SRC)/testBTree7Str.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBTree7Str.cpp -o $@
	
# Make all
all: testBSTNode1 testBSTNode2


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*