/**********************************************
* File: factorial.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function definitions 
* for the Header Example for Class
**********************************************/

#include "factorial.h"

/********************************************
* Function Name  : factInt
* Pre-conditions : int num
* Post-conditions: int
* 
* Takes in an int between 0 and 13, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
int factInt(int num){
	
	/* Error Checking */
	if(num < MIN_FACT || num > MAX_INT_FACT){
		COUT << num << " is invalid for integers\n";
		return -1;
	}
	
	/* 0! = 1 */
	if(num == 0){
		return 1;
	}
	
	return num * factInt(num - 1);
	
}


/********************************************
* Function Name  : factFloat
* Pre-conditions : int num
* Post-conditions: float
* 
* Takes in an int between 0 and 34, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
float factFloat(int num){
	
	/* Error Checking */
	if(num < MIN_FACT || num > MAX_FLOAT_FACT){
		COUT << num << " is invalid for floats\n";
		return -1;
	}
	
	/* 0! = 1 */
	if(num == 0){
		return 1;
	}
	
	return (float)num * factFloat(num - 1);
	
}


/********************************************
* Function Name  : factDouble
* Pre-conditions : int num
* Post-conditions: double
* 
* Takes in an int between 0 and 170, and returns the 
* factorial value. Returns -1 if those values are exceeded 
********************************************/
double factDouble(int num){
	
	/* Error Checking */
	if(num < MIN_FACT || num > MAX_DOUBLE_FACT){
		COUT << num << " is invalid for doubles\n";
		return -1;
	}
	
	/* 0! = 1 */
	if(num == 0){
		return 1;
	}
	
	return (double)num * factDouble(num - 1);
	
}
