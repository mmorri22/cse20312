# This is the Makefile for the CSE 20312 course Lecture 22

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



# Command: make MST
MSTObjs := $(OBJ)/MST.o 

MST: $(MSTObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST $(MSTObjs)
	$(EXE)/./MST

$(OBJ)/MST.o: $(SRC)/MST.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MST.cpp -o $@



# Command: make MST2
MST2Objs := $(OBJ)/MST2.o 

MST2: $(MST2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST2 $(MST2Objs)
	$(EXE)/./MST2

$(OBJ)/MST2.o: $(SRC)/MST2.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MST2.cpp -o $@



# Command: make Connected
ConnectedObjs := $(OBJ)/Connected.o 

Connected: $(ConnectedObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Connected $(ConnectedObjs)
	$(EXE)/./Connected

$(OBJ)/Connected.o: $(SRC)/Connected.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Connected.cpp -o $@	



# Command: make Union
UnionObjs := $(OBJ)/Union.o 

Union: $(UnionObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Union $(UnionObjs)
	$(EXE)/./Union

$(OBJ)/Union.o: $(SRC)/Union.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Union.cpp -o $@	



# Command: make numConnected
numConnectedObjs := $(OBJ)/numConnected.o 

numConnected: $(numConnectedObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/numConnected $(numConnectedObjs)
	$(EXE)/./numConnected

$(OBJ)/numConnected.o: $(SRC)/numConnected.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/numConnected.cpp -o $@		
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make all
all: testVert1 testVert2 testGraph1 Graph numConnected


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
