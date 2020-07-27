# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 02 - Part 2

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)



# namespace Example
# Command: make namespace
namespaceObjs :=  namespace.o

namespace: namespace.o
	$(PP) $(CXXFLAGS) -o namespace $(namespaceObjs)
	./namespace

namespace.o: namespace.cpp
	$(PP) $(CXXFLAGS) -c namespace.cpp
	
	
	
# nameGood Example
# Command: make nameGood
nameGoodObjs :=  nameGood.o

nameGood: nameGood.o
	$(PP) $(CXXFLAGS) -o nameGood $(nameGoodObjs)
	./nameGood

nameGood.o: nameGood.cpp
	$(PP) $(CXXFLAGS) -c nameGood.cpp


# nameGood2 Example
# Command: make nameGood2
nameGood2Objs :=  nameGood2.o

nameGood2: nameGood2.o
	$(PP) $(CXXFLAGS) -o nameGood2 $(nameGood2Objs)
	./nameGood2

nameGood2.o: nameGood2.cpp
	$(PP) $(CXXFLAGS) -c nameGood2.cpp



# voidTypes Example
# Command: make voidTypes
voidTypesObjs :=  voidTypes.o

voidTypes: voidTypes.o
	$(PP) $(CXXFLAGS) -o voidTypes $(voidTypesObjs)
	./voidTypes

voidTypes.o: voidTypes.cpp
	$(PP) $(CXXFLAGS) -c voidTypes.cpp


# voidTypes2 Example
# Command: make voidTypes2
voidTypes2Objs :=  voidTypes2.o

voidTypes2: voidTypes2.o
	$(PP) $(CXXFLAGS) -o voidTypes2 $(voidTypes2Objs)
	./voidTypes2

voidTypes2.o: voidTypes2.cpp
	$(PP) $(CXXFLAGS) -c voidTypes2.cpp



# voidTypes3 Example
# Command: make voidTypes3
voidTypes3Objs :=  voidTypes3.o

voidTypes3: voidTypes3.o
	$(PP) $(CXXFLAGS) -o voidTypes3 $(voidTypes3Objs)
	./voidTypes3

voidTypes3.o: voidTypes3.cpp
	$(PP) $(CXXFLAGS) -c voidTypes3.cpp
	
	

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
	

# Make all
all: namespace nameGood voidTypes voidTypes2 voidTypes3 voidNode voidNodeBad voidNodeBad2 structNode structSimple structMod classNode classMod classBad

# Make clean
clean :
	rm -rf *.o namespace nameGood nameGood2 voidTypes voidTypes2 voidTypes3 voidNode voidNodeBad voidNodeBad2 structNode structSimple structMod classNode classMod classBad
