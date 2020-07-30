/**********************************************
* File: array3.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a char array, set the first two
* bytes equal to characters, and then print their address
* and values
*
* Lecture 02 - - Slide 35
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
	char* reference = hello;
	
	*(reference) = 'H';
	reference = reference + 1;
	*(reference) = 'e';
	
	std::cout << &hello << " " << (void *)hello << " " << hello[0] << std::endl;
	std::cout << &reference << " " << (void *)reference << " " << *(reference) << std::endl;
	
	delete hello;

	return 0;
}
