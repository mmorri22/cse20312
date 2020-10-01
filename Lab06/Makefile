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



# Command: make Alien
AlienObjs := $(OBJ)/Alien.o 

Alien: $(AlienObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Alien $(AlienObjs)
	$(EXE)/./Alien

$(OBJ)/Alien.o: $(SRC)/Alien.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Alien.cpp -o $@


# Command: make Alien2
Alien2Objs := $(OBJ)/Alien2.o 

Alien2: $(Alien2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Alien2 $(Alien2Objs)
	$(EXE)/./Alien2

$(OBJ)/Alien2.o: $(SRC)/Alien2.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Alien2.cpp -o $@



# Command: make Alien3
Alien3Objs := $(OBJ)/Alien3.o 

Alien3: $(Alien3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Alien3 $(Alien3Objs)
	$(EXE)/./Alien3

$(OBJ)/Alien3.o: $(SRC)/Alien3.cpp $(INC)/Graph.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Alien3.cpp -o $@
	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make all
all: Alien Alien2


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
