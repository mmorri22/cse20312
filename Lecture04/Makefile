# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 03 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# passBy Example - Pass By Reference
# Command: make passBy
passByObjs :=  passBy.o

passBy: passBy.o
	$(PP) $(CXXFLAGS) -o passBy $(passByObjs)
	./passBy

passBy.o: passBy.cpp
	$(PP) $(CXXFLAGS) -c passBy.cpp	


# callBy Example - Call By Reference
# Command: make callBy
callByObjs :=  callBy.o

callBy: callBy.o
	$(PP) $(CXXFLAGS) -o callBy $(callByObjs)
	./callBy

callBy.o: callBy.cpp
	$(PP) $(CXXFLAGS) -c callBy.cpp	


# helloCmdLine Example - Shows how char** is structured
# Command: make helloCmdLine
helloCmdLineObjs :=  helloCmdLine.o

helloCmdLine: helloCmdLine.o
	$(PP) $(CXXFLAGS) -o helloCmdLine $(helloCmdLineObjs)
	./helloCmdLine Hello, World!

helloCmdLine.o: helloCmdLine.cpp
	$(PP) $(CXXFLAGS) -c helloCmdLine.cpp	


# array Example - Show how to call an array
# Command: make array
arrayObjs :=  array.o

array: array.o
	$(PP) $(CXXFLAGS) -o array $(arrayObjs)
	./array

array.o: array.cpp
	$(PP) $(CXXFLAGS) -c array.cpp	


# array2 Example - When the length is not known
# Command: make array
array2Objs :=  array2.o

array2: array2.o
	$(PP) $(CXXFLAGS) -o array2 $(array2Objs)
	./array2

array2.o: array2.cpp
	$(PP) $(CXXFLAGS) -c array2.cpp	


# procMatrix Example - MxN matrix in arrays
# Command: make procMatrix
procMatrixObjs :=  procMatrix.o

procMatrix: procMatrix.o
	$(PP) $(CXXFLAGS) -o procMatrix $(procMatrixObjs)
	./procMatrix

procMatrix.o: procMatrix.cpp
	$(PP) $(CXXFLAGS) -c procMatrix.cpp



# matrix Example - MxN matrix in arrays
# Command: make matrix
matrixObjs :=  matrix.o

matrix: matrix.o
	$(PP) $(CXXFLAGS) -o matrix $(matrixObjs)
	./matrix

matrix.o: matrix.cpp
	$(PP) $(CXXFLAGS) -c matrix.cpp	


# class1 Example 
# Command: make point1
class1Objs := class1.o point1.o

class1: $(class1Objs)
	$(PP) $(CXXFLAGS) -o class1 $(class1Objs)
	./class1

class1.o: class1.cpp point1.h
	$(PP) $(CXXFLAGS) -c class1.cpp

point1.o: point1.cpp point1.h
	$(PP) $(CXXFLAGS) -c point1.cpp


	
# class2 Example 
# Command: make point
class2Objs := class2.o point.o

class2: $(class2Objs)
	$(PP) $(CXXFLAGS) -o class2 $(class2Objs)
	./class2

class2.o: class2.cpp point.h
	$(PP) $(CXXFLAGS) -c class2.cpp



# class3 Example
# Command: make class3 
class3Objs := class3.o line1.o point.o

class3: $(class3Objs)
	$(PP) $(CXXFLAGS) -o class3 $(class3Objs)
	./class3

class3.o: class3.cpp line1.h
	$(PP) $(CXXFLAGS) -c class3.cpp

line1.o: line1.cpp line1.h
	$(PP) $(CXXFLAGS) -c line1.cpp
	
	
	
# class4 Example
# Command: make class4 
class4Objs := class4.o line2.o point.o

class4: $(class4Objs)
	$(PP) $(CXXFLAGS) -o class4 $(class4Objs)
	./class4

class4.o: class4.cpp line2.h
	$(PP) $(CXXFLAGS) -c class4.cpp

line2.o: line2.cpp line2.h
	$(PP) $(CXXFLAGS) -c line2.cpp
	


# classIntro Example
# Command: make classIntro 
classIntroObjs := classIntro.o line.o point.o

classIntro: $(classIntroObjs)
	$(PP) $(CXXFLAGS) -o classIntro $(classIntroObjs)
	./classIntro

classIntro.o: classIntro.cpp line.h
	$(PP) $(CXXFLAGS) -c classIntro.cpp

line.o: line.cpp line.h
	$(PP) $(CXXFLAGS) -c line.cpp

point.o: point.cpp point.h
	$(PP) $(CXXFLAGS) -c point.cpp



# Make all
all: passBy callBy helloCmdLine array array2 procMartix pascalTest matrix 

# Make clean
clean :
	rm -rf *.o passBy callBy helloCmdLine array array2 procMartix matrix
