/**********************************************
* File: void2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a void pointer and print all the addresses
* of the location of the characters
*
* Lecture 02 - Slides 27-28
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
	
	void* hello = malloc( numCharacters * sizeof(char) );
	
	for(long unsigned int iter = 0; iter < numCharacters; iter++){
	
		// Secure way of performing pointer arithmetic on void pointers
		std::cout << (void *) ((char*)hello + iter*sizeof(int)) << std::endl;
	
	}
	
	free( hello );

	return 0;
}
