# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lab 02

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make vector
vectorObjs := $(OBJ)/vector.o

vector: $(vectorObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/vector $(vectorObjs)
	$(EXE)/./vector

$(OBJ)/vector.o: $(SRC)/vector.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/vector.cpp -o $@


# Command: make sol_1
sol_1Objs := $(OBJ)/sol_1.o

sol_1: $(sol_1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sol_1 $(sol_1Objs)
	$(EXE)/./sol_1

$(OBJ)/sol_1.o: $(SRC)/sol_1.cpp $(INC)/sol1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/sol_1.cpp -o $@



# Command: make sol_2
sol_2Objs := $(OBJ)/sol_2.o

sol_2: $(sol_2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sol_2 $(sol_2Objs)
	$(EXE)/./sol_2

$(OBJ)/sol_2.o: $(SRC)/sol_2.cpp $(INC)/sol2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/sol_2.cpp -o $@
	
	
# Command: make sol_3
sol_3Objs := $(OBJ)/sol_3.o

sol_3: $(sol_3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sol_3 $(sol_3Objs)
	$(EXE)/./sol_3

$(OBJ)/sol_3.o: $(SRC)/sol_3.cpp $(INC)/sol3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/sol_3.cpp -o $@


# Command: make sol
solObjs := $(OBJ)/sol.o

sol: $(solObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sol $(solObjs)
	$(EXE)/./sol

$(OBJ)/sol.o: $(SRC)/sol.cpp $(INC)/sol.h
	$(PP) $(CXXFLAGS) -c $(SRC)/sol.cpp -o $@


# Command: make Product
ProductObjs := $(OBJ)/Product.o

Product: $(ProductObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Product $(ProductObjs)
	$(EXE)/./Product

$(OBJ)/Product.o: $(SRC)/Product.cpp $(INC)/Product.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Product.cpp -o $@



# Command: make Product1
Product1Objs := $(OBJ)/Product1.o

Product1: $(Product1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Product1 $(Product1Objs)
	$(EXE)/./Product1

$(OBJ)/Product1.o: $(SRC)/Product1.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Product1.cpp -o $@


# Command: make Product2
Product2Objs := $(OBJ)/Product2.o

Product2: $(Product2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Product2 $(Product2Objs)
	$(EXE)/./Product2

$(OBJ)/Product2.o: $(SRC)/Product2.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Product2.cpp -o $@



# Command: make Product3
Product3Objs := $(OBJ)/Product3.o

Product3: $(Product3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Product3 $(Product3Objs)
	$(EXE)/./Product3

$(OBJ)/Product3.o: $(SRC)/Product3.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Product3.cpp -o $@
	


# Command: make maxSub1
maxSub1Objs := $(OBJ)/maxSub1.o

maxSub1: $(maxSub1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub1 $(maxSub1Objs)
	$(EXE)/./maxSub1

$(OBJ)/maxSub1.o: $(SRC)/maxSub1.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxSub1.cpp -o $@



# Command: make maxSub2
maxSub2Objs := $(OBJ)/maxSub2.o

maxSub2: $(maxSub2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub2 $(maxSub2Objs)
	$(EXE)/./maxSub2

$(OBJ)/maxSub2.o: $(SRC)/maxSub2.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxSub2.cpp -o $@



# Command: make maxSub3
maxSub3Objs := $(OBJ)/maxSub3.o

maxSub3: $(maxSub3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub3 $(maxSub3Objs)
	$(EXE)/./maxSub3

$(OBJ)/maxSub3.o: $(SRC)/maxSub3.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxSub3.cpp -o $@



# Command: make maxSub4
maxSub4Objs := $(OBJ)/maxSub4.o

maxSub4: $(maxSub4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub4 $(maxSub4Objs)
	$(EXE)/./maxSub4

$(OBJ)/maxSub4.o: $(SRC)/maxSub4.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxSub4.cpp -o $@



# Command: make maxSub
maxSubObjs := $(OBJ)/maxSub.o

maxSub: $(maxSubObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxSub $(maxSubObjs)
	$(EXE)/./maxSub

$(OBJ)/maxSub.o: $(SRC)/maxSub.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxSub.cpp -o $@



# Command: make maxProd1
maxProd1Objs := $(OBJ)/maxProd1.o

maxProd1: $(maxProd1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxProd1 $(maxProd1Objs)
	$(EXE)/./maxProd1

$(OBJ)/maxProd1.o: $(SRC)/maxProd1.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxProd1.cpp -o $@



# Command: make maxProd
maxProdObjs := $(OBJ)/maxProd.o

maxProd: $(maxProdObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/maxProd $(maxProdObjs)
	$(EXE)/./maxProd

$(OBJ)/maxProd.o: $(SRC)/maxProd.cpp $(INC)/DynArr.h
	$(PP) $(CXXFLAGS) -c $(SRC)/maxProd.cpp -o $@
	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables
	


# Make all
all: sol_1 sol_2 sol_3 sol Product1 Product2

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
