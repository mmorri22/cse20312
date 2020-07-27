# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 02 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)



# C++ Hello, World Example
# Command: make hello
helloObjs :=  hello.o

hello: hello.o
	$(PP) $(CXXFLAGS) -o hello $(helloObjs)
	./hello

hello.o: hello.cpp
	$(PP) $(CXXFLAGS) -c hello.cpp
	


# C++ void1, World Example
# Command: make void1
void1Objs :=  void1.o

void1: void1.o
	$(PP) $(CXXFLAGS) -o void1 $(void1Objs)
	./void1

void1.o: void1.cpp
	$(PP) $(CXXFLAGS) -c void1.cpp
	
	
# C++ void2, World Example
# Command: make void2
void2Objs :=  void2.o

void2: void2.o
	$(PP) $(CXXFLAGS) -o void2 $(void2Objs)
	./void2

void2.o: void2.cpp
	$(PP) $(CXXFLAGS) -c void2.cpp
	
	
# C++ void3, World Example
# Command: make void3
void3Objs :=  void3.o

void3: void3.o
	$(PP) $(CXXFLAGS) -o void3 $(void3Objs)
	./void3

void3.o: void3.cpp
	$(PP) $(CXXFLAGS) -c void3.cpp
	
	
# C++ void4, World Example
# Command: make void4
void4Objs :=  void4.o

void4: void4.o
	$(PP) $(CXXFLAGS) -o void4 $(void4Objs)
	./void4

void4.o: void4.cpp
	$(PP) $(CXXFLAGS) -c void4.cpp
	
	
	
# C++ helloVoid, World Example
# Command: make helloVoid
helloVoidObjs :=  helloVoid.o

helloVoid: helloVoid.o
	$(PP) $(CXXFLAGS) -o helloVoid $(helloVoidObjs)
	./helloVoid

helloVoid.o: helloVoid.cpp
	$(PP) $(CXXFLAGS) -c helloVoid.cpp



# C++ char1, World Example
# Command: make char1
char1Objs :=  char1.o

char1: char1.o
	$(PP) $(CXXFLAGS) -o char1 $(char1Objs)
	./char1

char1.o: char1.cpp
	$(PP) $(CXXFLAGS) -c char1.cpp
	
	
	
# C++ char2, World Example
# Command: make char2
char2Objs :=  char2.o

char2: char2.o
	$(PP) $(CXXFLAGS) -o char2 $(char2Objs)
	./char2

char2.o: char2.cpp
	$(PP) $(CXXFLAGS) -c char2.cpp



# C++ char3, World Example
# Command: make char3
char3Objs :=  char3.o

char3: char3.o
	$(PP) $(CXXFLAGS) -o char3 $(char3Objs)
	./char3

char3.o: char3.cpp
	$(PP) $(CXXFLAGS) -c char3.cpp
	
	
# C++ char4, World Example
# Command: make char4
char4Objs :=  char4.o

char4: char4.o
	$(PP) $(CXXFLAGS) -o char4 $(char4Objs)
	./char4

char4.o: char4.cpp
	$(PP) $(CXXFLAGS) -c char4.cpp


# C++ helloChar, World Example
# Command: make helloChar
helloCharObjs :=  helloChar.o

helloChar: helloChar.o
	$(PP) $(CXXFLAGS) -o helloChar $(helloCharObjs)
	./helloChar

helloChar.o: helloChar.cpp
	$(PP) $(CXXFLAGS) -c helloChar.cpp
	
	
	
# C++ array1, World Example
# Command: make array1
array1Objs :=  array1.o

array1: array1.o
	$(PP) $(CXXFLAGS) -o array1 $(array1Objs)
	./array1

array1.o: array1.cpp
	$(PP) $(CXXFLAGS) -c array1.cpp
	
	
	
# C++ array2, World Example
# Command: make array2
array2Objs :=  array2.o

array2: array2.o
	$(PP) $(CXXFLAGS) -o array2 $(array2Objs)
	./array2

array2.o: array2.cpp
	$(PP) $(CXXFLAGS) -c array2.cpp



# C++ array3, World Example
# Command: make array3
array3Objs :=  array3.o

array3: array3.o
	$(PP) $(CXXFLAGS) -o array3 $(array3Objs)
	./array3

array3.o: array3.cpp
	$(PP) $(CXXFLAGS) -c array3.cpp
	
	
# C++ array4, World Example
# Command: make array4
array4Objs :=  array4.o

array4: array4.o
	$(PP) $(CXXFLAGS) -o array4 $(array4Objs)
	./array4

array4.o: array4.cpp
	$(PP) $(CXXFLAGS) -c array4.cpp


# C++ helloArray, World Example
# Command: make helloArray
helloArrayObjs :=  helloArray.o

helloArray: helloArray.o
	$(PP) $(CXXFLAGS) -o helloArray $(helloArrayObjs)
	./helloArray

helloArray.o: helloArray.cpp
	$(PP) $(CXXFLAGS) -c helloArray.cpp
	
	
# C++ helloArray2, World Example
# Command: make helloArray2
helloArray2Objs :=  helloArray2.o

helloArray2: helloArray2.o
	$(PP) $(CXXFLAGS) -o helloArray2 $(helloArray2Objs)
	./helloArray2

helloArray2.o: helloArray2.cpp
	$(PP) $(CXXFLAGS) -c helloArray2.cpp
	
	
# C++ helloArray3, World Example
# Command: make helloArray3
helloArray3Objs :=  helloArray3.o

helloArray3: helloArray3.o
	$(PP) $(CXXFLAGS) -o helloArray3 $(helloArray3Objs)
	./helloArray3

helloArray3.o: helloArray3.cpp
	$(PP) $(CXXFLAGS) -c helloArray3.cpp


# Make all
all: nothing hello ascii squareFunc

# Make clean
clean :
	rm -rf *.o nothing hello intPtr void1 void2 void3 void4 helloVoid char1 char2 char3 char4 helloChar array1 array2 array3 array4 helloArray helloArray2 helloArray3
