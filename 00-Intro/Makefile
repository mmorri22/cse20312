# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 04

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)



# C++ Hello, World Example
# Command: make hello
helloObjs :=  hello.o

hello: hello.o
	$(PP) $(CXXFLAGS) -o hello $(helloObjs)
	./hello

hello.o: hello.cpp
	$(PP) $(CXXFLAGS) -c hello.cpp


# Make all
all: hello

# Make clean
clean :
	rm -rf *.o hello
	
	
# Begin and Checkout the branch
initial :
	cd ..
	git checkout master
	git pull --rebase
	git checkout -b 00-Intro
	cd 00-Intro
	
next :
	cd ..
	git checkout master
	git pull --rebase
	git checkout 00-Intro
	cd 00-Intro

	
git :
	make clean
	git add *
	git commit -m "Update 00-Intro"
	git push -u origin 00-Intro
