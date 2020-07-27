/**********************************************
* File: char1.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a char pointer and print its address
*
* Lecture 02 - Part 1 - Slides 21-22
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
	
	std::cout << (void *)hello << std::endl;
	
	free( hello );

	return 0;
}

