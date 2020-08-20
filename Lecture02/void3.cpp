/**********************************************
* File: void3.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a void point and memory, set the first two
* bytes equal to characters, and then print their 
*
* Lecture 02 - Slides 30-32
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
	void* reference = hello;
	
	*((char *)(reference)) = ;
	reference = reference + sizeof(char);
	*((char *)(reference)) = 101;
	
	std::cout << &hello << " " << hello << " " << *((char *)(hello)) <<std::endl;
	std::cout << &reference << " " << reference << " " << *((char *)(reference)) << std::endl;
	
	free( hello );

	return 0;
}
