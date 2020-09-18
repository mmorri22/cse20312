# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lecture 18

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make wrapper
wrapperQueueObjs :=  $(OBJ)/wrapperQueue.o

wrapperQueue: $(wrapperQueueObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/wrapperQueue $(wrapperQueueObjs)
	$(EXE)/./wrapperQueue

$(OBJ)/wrapperQueue.o: $(SRC)/wrapperQueue.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/wrapperQueue.cpp -o $@
	


# Command: make wrapperStack
wrapperStackObjs :=  $(OBJ)/wrapperStack.o

wrapperStack: $(wrapperStackObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/wrapperStack $(wrapperStackObjs)
	$(EXE)/./wrapperStack

$(OBJ)/wrapperStack.o: $(SRC)/wrapperStack.cpp $(INC)/stack.h
	$(PP) $(CXXFLAGS) -c $(SRC)/wrapperStack.cpp -o $@



# Command: make wrapperStack
stackTestObjs :=  $(OBJ)/stackTest.o

stackTest: $(stackTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/stackTest $(stackTestObjs)
	$(EXE)/./stackTest

$(OBJ)/stackTest.o: $(SRC)/stackTest.cpp $(INC)/stack.h
	$(PP) $(CXXFLAGS) -c $(SRC)/stackTest.cpp -o $@	


# Command: make shortestPath1
shortestPath1Objs :=  $(OBJ)/shortestPath1.o

shortestPath1: $(shortestPath1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/shortestPath1 $(shortestPath1Objs)
	$(EXE)/./shortestPath1

$(OBJ)/shortestPath1.o: $(SRC)/shortestPath1.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/shortestPath1.cpp -o $@



# Command: make shortestPath2
shortestPath2Objs :=  $(OBJ)/shortestPath2.o

shortestPath2: $(shortestPath2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/shortestPath2 $(shortestPath2Objs)
	$(EXE)/./shortestPath2

$(OBJ)/shortestPath2.o: $(SRC)/shortestPath2.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/shortestPath2.cpp -o $@



# Command: make shortestPath3
shortestPath3Objs :=  $(OBJ)/shortestPath3.o

shortestPath3: $(shortestPath3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/shortestPath3 $(shortestPath3Objs)
	$(EXE)/./shortestPath3

$(OBJ)/shortestPath3.o: $(SRC)/shortestPath3.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/shortestPath3.cpp -o $@
	
	


# Command: make shortestPath
shortestPathObjs :=  $(OBJ)/shortestPath.o

shortestPath: $(shortestPathObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/shortestPath $(shortestPathObjs)
	$(EXE)/./shortestPath

$(OBJ)/shortestPath.o: $(SRC)/shortestPath.cpp $(INC)/queue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/shortestPath.cpp -o $@


	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)	


# Make all
all: wrapperQueue wrapperStack

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
