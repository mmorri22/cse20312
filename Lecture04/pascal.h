/**********************************************
* File: pascal.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Reviewing the use of Header Files in C/C++
*
* Lecture 04 - Slide 24
**********************************************/

#ifndef PASCAL_H
#define PASCAL_H

#include <iostream>

// You will learn about #define in Lab 1
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

// Get the number of levels from the user
unsigned int getNumLevels();

// Create a memory efficient Pascal Triangle of numLevels height
unsigned int** createPascal(unsigned int numLevels);

// Print the Pascal's Triangle of numLevels height
void printPascal( unsigned int** pascalTri, unsigned int numLevels );

// Run the inputs from the user of Pascal's Triangle of numLevels height
void runTests( unsigned int** pascalTri, unsigned int numLevels );

// Free all the memory allocated to the Pascal Triangle 
void freePascal( unsigned int** pascalTri, unsigned int numLevels );

#endif