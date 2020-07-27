/**********************************************
* File: fact_01.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Step 1 for setting up a .cpp File with function
* definitions from a Header file. First example 
* of a function definition 
*
* Correlates with fact_02.h
*
* Lecture 03 - Part 2 - Slide 5
**********************************************/

#include "fact_02.h"

int factInt(int num){
	
	/* 0! = 1 */
	if(num == 0){
		return 1;
	}
	
	return num * factInt(num - 1);
	
}


