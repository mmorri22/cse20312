/**********************************************
* File: array4.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a char array, sets all the characters
* to Hello, World, and then prints their addresses and values
*
* Lecture 02 - Slide 38
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
		
		std::cout << (void *)reference << " " << *(reference) << " " << (void *)(hello + iter) << " " << hello[iter] << std::endl;
		
		reference = reference + 1;
		
	}
	
	delete hello;

	return 0;
}
