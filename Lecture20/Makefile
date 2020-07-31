# This is the Makefile for the CSE 20312 course Lecture 20

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

$(OBJ)/MST.o: $(SRC)/MST.cpp $(INC)/Graph4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MST.cpp -o $@


# Command: make MST2
MST2Objs := $(OBJ)/MST2.o 

MST2: $(MST2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST2 $(MST2Objs)
	$(EXE)/./MST2

$(OBJ)/MST2.o: $(SRC)/MST2.cpp $(INC)/Graph4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/MST2.cpp -o $@



# Command: make DFS
DFSObjs := $(OBJ)/DFS.o 

DFS: $(DFSObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DFS $(DFSObjs)
	$(EXE)/./DFS

$(OBJ)/DFS.o: $(SRC)/DFS.cpp $(INC)/Graph5.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DFS.cpp -o $@


# Command: make DFS2
DFS2Objs := $(OBJ)/DFS2.o 

DFS2: $(DFS2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DFS2 $(DFS2Objs)
	$(EXE)/./DFS2

$(OBJ)/DFS2.o: $(SRC)/DFS2.cpp $(INC)/Graph5.h
	$(PP) $(CXXFLAGS) -c $(SRC)/DFS2.cpp -o $@
	
	
# Command: make TopSort
TopSortObjs := $(OBJ)/TopSort.o 

TopSort: $(TopSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TopSort $(TopSortObjs)
	$(EXE)/./TopSort

$(OBJ)/TopSort.o: $(SRC)/TopSort.cpp $(INC)/Graph6.h
	$(PP) $(CXXFLAGS) -c $(SRC)/TopSort.cpp -o $@


# Command: make PERT
PERTObjs := $(OBJ)/PERT.o 

PERT: $(PERTObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PERT $(PERTObjs)
	$(EXE)/./PERT

$(OBJ)/PERT.o: $(SRC)/PERT.cpp $(INC)/Graph6.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PERT.cpp -o $@


# Command: make Dijkstra
DijkstraObjs := $(OBJ)/Dijkstra.o 

Dijkstra: $(DijkstraObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Dijkstra $(DijkstraObjs)
	$(EXE)/./Dijkstra

$(OBJ)/Dijkstra.o: $(SRC)/Dijkstra.cpp $(INC)/Graph7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Dijkstra.cpp -o $@	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: testVert1 testVert2 testGraph1 Graph


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
