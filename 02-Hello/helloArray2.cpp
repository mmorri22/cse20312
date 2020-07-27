/**********************************************
* File: helloArray.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of "Hello, World" with procedural
* programming, char array, and array[] operators
*
* Lecture 02 - Part 1 - Slide 31
**********************************************/

#include <iostream>
#include <cstdlib>

/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(void){
	
	long unsigned int numCharacters = 13;
	
	char* hello = new char[numCharacters];
	
	hello[0] = 'H';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = ',';
	hello[6] = ' ';
	hello[7] = 'W';
	hello[8] = 'o';
	hello[9] = 'r';
	hello[10] = 'l';
	hello[11] = 'd';
	hello[12] = '\n';
	
	for(long unsigned int iter = 0; iter < numCharacters; iter++){
		
		std::cout << hello[iter];
	}
	
	free( hello );

	return 0;
}
