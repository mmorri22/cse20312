# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 05 - Part 1
# 
# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)
	
	
	
# Fibonacci Example
# Command: make fib
fibObjs := fib.o

fib: $(fibObjs)
	$(PP) $(CXXFLAGS) -o fib $(fibObjs)

fib.o: fib.cpp
	$(PP) $(CXXFLAGS) -c fib.cpp



# Merge Sort Design - Part 1
# Command: make merge1
merge1Objs := merge1.o

merge1: $(merge1Objs)
	$(PP) $(CXXFLAGS) -o merge1 $(merge1Objs)
	./merge1

merge1.o: merge1.cpp
	$(PP) $(CXXFLAGS) -c merge1.cpp
	
	
	
# Merge Sort Design - Part 2
# Command: make merge2
merge2Objs := merge2.o

merge2: $(merge2Objs)
	$(PP) $(CXXFLAGS) -o merge2 $(merge2Objs)
	./merge2

merge2.o: merge2.cpp
	$(PP) $(CXXFLAGS) -c merge2.cpp
	
	
# Merge Sort Design - Part 3
# Command: make merge3
merge3Objs := merge3.o

merge3: $(merge3Objs)
	$(PP) $(CXXFLAGS) -o merge3 $(merge3Objs)
	./merge3

merge3.o: merge3.cpp
	$(PP) $(CXXFLAGS) -c merge3.cpp



# Merge Sort Design - Part 4
# Command: make merge4
merge4Objs := merge4.o

merge4: $(merge4Objs)
	$(PP) $(CXXFLAGS) -o merge4 $(merge4Objs)
	./merge4

merge4.o: merge4.cpp
	$(PP) $(CXXFLAGS) -c merge4.cpp
	
	
	
# Merge Sort Design - Final
# Command: make merge
mergeObjs := merge.o

merge: $(mergeObjs)
	$(PP) $(CXXFLAGS) -o merge $(mergeObjs)
	./merge

merge.o: merge.cpp
	$(PP) $(CXXFLAGS) -c merge.cpp
	

# Make all
all: exp1 exp2 exp fib merge1 merge2 merge3 merge4 merge

# Make clean
clean :
	rm -rf *.o exp1 exp2 exp fib merge1 merge2 merge3 merge4 merge