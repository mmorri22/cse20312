/**********************************************
* File: factorial.h 
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function prototypes 
* for the Header Example for Class
**********************************************/

#ifndef FACTORIAL_H
#define FACTORIAL_H

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
* Takes in an int between 0 and 13, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
int factInt(int num);


/********************************************
* Function Name  : factFloat
* Pre-conditions : int num
* Post-conditions: float
* 
* Takes in an int between 0 and 34, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
float factFloat(int num);


/********************************************
* Function Name  : factDouble
* Pre-conditions : int num
* Post-conditions: double
* 
* Takes in an int between 0 and 170, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
double factDouble(int num);


#endif
