/**********************************************
* File: fact_03_run.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains an introductory example of 
* using header files to simplify and re-use code 
**********************************************/

#include "fact_03.h"

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
