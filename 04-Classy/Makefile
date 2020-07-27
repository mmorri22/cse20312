# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 03 - Part 2

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# fact_02_run Example
# Command: make fact_02_run 
fact_02_runObjs :=  fact_02_run.o fact_02.o

fact_02_run: $(fact_02_runObjs)
	$(PP) $(CXXFLAGS) -o fact_02_run $(fact_02_runObjs)
	./fact_02_run

fact_02_run.o: fact_02_run.cpp fact_02.h
	$(PP) $(CXXFLAGS) -c fact_02_run.cpp

fact_02.o: fact_02.cpp fact_02.h
	$(PP) $(CXXFLAGS) -c fact_02.cpp



# fact_03_run Example
# Command: make fact_03_run 
fact_03_runObjs :=  fact_03_run.o fact_03.o

fact_03_run: $(fact_03_runObjs)
	$(PP) $(CXXFLAGS) -o fact_03_run $(fact_03_runObjs)
	./fact_03_run

fact_03_run.o: fact_03_run.cpp fact_03.h
	$(PP) $(CXXFLAGS) -c fact_03_run.cpp

fact_03.o: fact_03.cpp fact_03.h
	$(PP) $(CXXFLAGS) -c fact_03.cpp
	
	
	
# factHeaderEx Example
# Command: make factHeaderEx 

factHeaderExObjs := factorial.o factHeaderEx.o

factHeaderEx: $(factHeaderExObjs)
	$(PP) $(CXXFLAGS) -o factHeaderEx $(factHeaderExObjs)
	./factHeaderEx

factHeaderEx.o: factHeaderEx.cpp factorial.h
	$(PP) $(CXXFLAGS) -c factHeaderEx.cpp

factorial.o: factorial.cpp factorial.h
	$(PP) $(CXXFLAGS) -c factorial.cpp
	


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
all: fact_02_run fact_03_run factHeaderEx classIntro

# Make clean
clean :
	rm -rf *.o fact_02_run fact_03_run factHeaderEx classIntro
