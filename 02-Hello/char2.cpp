/**********************************************
* File: char2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a char pointer and memory and print all the addresses
* of the location of the characters
*
* Lecture 02 - Slide 29
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
	
	char* hello = (char *)malloc( numCharacters * sizeof(char) );
	
	for(long unsigned int iter = 0; iter < numCharacters; iter++){
	
		std::cout << (void *)(hello + iter) << std::endl;
	
	}
	
	free( hello );

	return 0;
}
