/**********************************************
* File: fact_03.h 
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Step 1 for setting up a Header File
*
* Correlates with fact_01.cpp
**********************************************/

#ifndef FACT_03_H
#define FACT_03_H

#include <iostream>

#define COUT std::cout
#define ENDL std::endl

/* Compiler Directives */
const int MIN_FACT = 0;
const int MAX_INT_FACT = 12;
const int MAX_FLOAT_FACT = 34;
const int MAX_DOUBLE_FACT = 170;

/********************************************
* Function Name  : factInt
* Pre-conditions : int num
* Post-conditions: int
* 
* Takes in an int between 0 and 12, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
int factInt(int num);

#endif
