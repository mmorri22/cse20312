# This is the Makefile for the CSE 20312 course Lecture 21

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

# Command: make Dijkstra
# Initial Examples of Dijkstra
DijkstraObjs := $(OBJ)/Dijkstra.o 

Dijkstra: $(DijkstraObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Dijkstra $(DijkstraObjs)
	$(EXE)/./Dijkstra

$(OBJ)/Dijkstra.o: $(SRC)/Dijkstra.cpp $(INC)/Graph7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Dijkstra.cpp -o $@
	
	
# Command: make BFS
# Initial Examples of pthreads
BFSObjs := $(OBJ)/BFS.o 

BFS: $(BFSObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BFS $(BFSObjs)
	$(EXE)/./BFS

$(OBJ)/BFS.o: $(SRC)/BFS.cpp $(INC)/Graph7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/BFS.cpp -o $@


# Command: make BFS2
# Initial Examples of pthreads
BFS2Objs := $(OBJ)/BFS2.o 

BFS2: $(BFS2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BFS2 $(BFS2Objs)
	$(EXE)/./BFS2

$(OBJ)/BFS2.o: $(SRC)/BFS2.cpp $(INC)/Graph8.h
	$(PP) $(CXXFLAGS) -c $(SRC)/BFS2.cpp -o $@



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
	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: testVert1 testVert2 testGraph1 Graph


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
