/**********************************************
* File: factHeaderEx.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains an introductory example of 
* using header files to simplify and re-use code 
**********************************************/

#include "fact_02.h"

#include <iostream>

#define COUT std::cout
#define ENDL std::endl

/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(void){
	
	for(int iter = 0; iter < 20; iter++){
		
		COUT << factInt( iter ) << ENDL;
	}
	
	return 0;
}
