# This is the Makefile for the CSE 20312 course - Optional Lecture 07

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
	
	
	
# Command: make testMinHeap
PalPartObjs := $(OBJ)/PalPart.o 

PalPart: $(PalPartObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PalPart $(PalPartObjs)
	$(EXE)/./PalPart

$(OBJ)/PalPart.o: $(SRC)/PalPart.cpp $(INC)/PalPart.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PalPart.cpp -o $@



# Command: make GoogleVec
GoogleVecObjs := $(OBJ)/GoogleVec.o 

GoogleVec: $(GoogleVecObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleVec $(GoogleVecObjs)
	$(EXE)/./GoogleVec words.txt

$(OBJ)/GoogleVec.o: $(SRC)/GoogleVec.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleVec.cpp -o $@



# Command: make GoogleForwList
GoogleForwListObjs := $(OBJ)/GoogleForwList.o 

GoogleForwList: $(GoogleForwListObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleForwList $(GoogleForwListObjs)
	$(EXE)/./GoogleForwList words.txt

$(OBJ)/GoogleForwList.o: $(SRC)/GoogleForwList.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleForwList.cpp -o $@



# Command: make GoogleHash
GoogleHashObjs := $(OBJ)/GoogleHash.o 

GoogleHash: $(GoogleHashObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleHash $(GoogleHashObjs)
	$(EXE)/./GoogleHash words.txt

$(OBJ)/GoogleHash.o: $(SRC)/GoogleHash.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleHash.cpp -o $@


# Command: make GoogleIFS
GoogleIFSObjs := $(OBJ)/GoogleIFS.o 

GoogleIFS: $(GoogleIFSObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleIFS $(GoogleIFSObjs)
	$(EXE)/./GoogleIFS words.txt

$(OBJ)/GoogleIFS.o: $(SRC)/GoogleIFS.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleIFS.cpp -o $@	


# Command: make GoogleList
GoogleListObjs := $(OBJ)/GoogleList.o 

GoogleList: $(GoogleListObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleList $(GoogleListObjs)
	$(EXE)/./GoogleList words.txt

$(OBJ)/GoogleList.o: $(SRC)/GoogleList.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleList.cpp -o $@



# Command: make GoogleMap
GoogleMapObjs := $(OBJ)/GoogleMap.o 

GoogleMap: $(GoogleMapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleMap $(GoogleMapObjs)
	$(EXE)/./GoogleMap words.txt

$(OBJ)/GoogleMap.o: $(SRC)/GoogleMap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleMap.cpp -o $@



# Command: make GoogleSet
GoogleSetObjs := $(OBJ)/GoogleSet.o 

GoogleSet: $(GoogleSetObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleSet $(GoogleSetObjs)
	$(EXE)/./GoogleSet words.txt

$(OBJ)/GoogleSet.o: $(SRC)/GoogleSet.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleSet.cpp -o $@



# Command: make GoogleUnorMap
GoogleUnorMapObjs := $(OBJ)/GoogleUnorMap.o 

GoogleUnorMap: $(GoogleUnorMapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/GoogleUnorMap $(GoogleUnorMapObjs)
	$(EXE)/./GoogleUnorMap words.txt

$(OBJ)/GoogleUnorMap.o: $(SRC)/GoogleUnorMap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/GoogleUnorMap.cpp -o $@

	
	
# Make all
all: PalPart GoogleVec



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
