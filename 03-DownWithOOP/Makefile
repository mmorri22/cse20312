# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 03 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)
	
	

# voidNode Example
# Command: make voidNode
voidNodeObjs :=  voidNode.o

voidNode: voidNode.o
	$(PP) $(CXXFLAGS) -o voidNode $(voidNodeObjs)
	./voidNode

voidNode.o: voidNode.cpp
	$(PP) $(CXXFLAGS) -c voidNode.cpp
	
	
	
# voidNodeBad Example
# Command: make voidNodeBad
voidNodeBadObjs :=  voidNodeBad.o

voidNodeBad: voidNodeBad.o
	$(PP) $(CXXFLAGS) -o voidNodeBad $(voidNodeBadObjs)
	./voidNodeBad

voidNodeBad.o: voidNodeBad.cpp
	$(PP) $(CXXFLAGS) -c voidNodeBad.cpp



# voidNodeBad2 Example
# Command: make voidNodeBad2
voidNodeBad2Objs :=  voidNodeBad2.o

voidNodeBad2: voidNodeBad2.o
	$(PP) $(CXXFLAGS) -o voidNodeBad2 $(voidNodeBad2Objs)
	./voidNodeBad2

voidNodeBad2.o: voidNodeBad2.cpp
	$(PP) $(CXXFLAGS) -c voidNodeBad2.cpp
	


# structNode Example
# Command: make structNode
structNodeObjs :=  structNode.o

structNode: structNode.o
	$(PP) $(CXXFLAGS) -o structNode $(structNodeObjs)
	./structNode

structNode.o: structNode.cpp
	$(PP) $(CXXFLAGS) -c structNode.cpp


# structSimple Example
# Command: make structSimple
structSimpleObjs :=  structSimple.o

structSimple: structSimple.o
	$(PP) $(CXXFLAGS) -o structSimple $(structSimpleObjs)
	./structSimple

structSimple.o: structSimple.cpp
	$(PP) $(CXXFLAGS) -c structSimple.cpp
	

	
# structMod Example
# Command: make structMod
structModObjs :=  structMod.o

structMod: structMod.o
	$(PP) $(CXXFLAGS) -o structMod $(structModObjs)
	./structMod

structMod.o: structMod.cpp
	$(PP) $(CXXFLAGS) -c structMod.cpp


# classNode Example
# Command: make classNode
classNodeObjs :=  classNode.o

classNode: classNode.o
	$(PP) $(CXXFLAGS) -o classNode $(classNodeObjs)
	./classNode

classNode.o: classNode.cpp
	$(PP) $(CXXFLAGS) -c classNode.cpp
	
	
# classMod Example
# Command: make classMod
classModObjs :=  classMod.o

classMod: classMod.o
	$(PP) $(CXXFLAGS) -o classMod $(classModObjs)
	./classMod

classMod.o: classMod.cpp
	$(PP) $(CXXFLAGS) -c classMod.cpp
	
	
# classBad Example
# Command: make classBad
classBadObjs :=  classBad.o

classBad: classBad.o
	$(PP) $(CXXFLAGS) -o classBad $(classBadObjs)
	./classBad

classBad.o: classBad.cpp
	$(PP) $(CXXFLAGS) -c classBad.cpp
	
	
	
# classBadPQC Example
# Command: make classBadPQC
classBadPQCObjs :=  classBadPQC.o

classBadPQC: classBadPQC.o
	$(PP) $(PQCXX) -o classBadPQC $(classBadPQCObjs)
	./classBadPQC

classBadPQC.o: classBad.cpp
	$(PP) $(PQCXX) -c classBad.cpp
	
	

# const Example
# Command: make const
constObjs :=  const.o

const: const.o
	$(PP) $(PQCXX) -o const $(constObjs)
	./const

const.o: const.cpp
	$(PP) $(PQCXX) -c const.cpp
	
	
	
# funcOver Example
# Command: make funcOver
funcOverObjs :=  funcOver.o

funcOver: funcOver.o
	$(PP) $(PQCXX) -o funcOver $(funcOverObjs)
	./funcOver

funcOver.o: funcOver.cpp
	$(PP) $(PQCXX) -c funcOver.cpp
	
	
	
# ambig Example
# Command: make ambig
ambigObjs :=  ambig.o

ambig: ambig.o
	$(PP) $(PQCXX) -o ambig $(ambigObjs)
	./ambig

ambig.o: ambig.cpp
	$(PP) $(PQCXX) -c ambig.cpp



# template Example
# Command: make template
templateObjs :=  template.o

template: template.o
	$(PP) $(PQCXX) -o template $(templateObjs)
	./template

template.o: template.cpp
	$(PP) $(PQCXX) -c template.cpp
	

# Make all
all: voidNode voidNodeBad voidNodeBad2 structNode structSimple structMod classNode classMod classBad const funcOver template

# Make clean
clean :
	rm -rf *.o voidNode voidNodeBad voidNodeBad2 structNode structSimple structMod classNode classMod classBad const funcOver template
