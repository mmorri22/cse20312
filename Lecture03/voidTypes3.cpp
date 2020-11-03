/**********************************************
* File: voidTypes.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating different types using the
* same void pointer
*
* Lecture 3 - Slide 10
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main(void){
	
	void* numbers = malloc( sizeof(double) + sizeof(float) + sizeof(int) );
	void* reference = numbers;
	
	// Put a double in the first 64 bits after reference
	*((double *)(reference)) = -0.625;
	
	// Move past 64 bits and put in a float 
	reference = (void *) ( (double *)reference + sizeof(double) );
	*((float *)(reference)) = 1.5625;
	
	// Move past 32 bits and put in an integer
	reference = (void *) ( (float *)reference + sizeof(float) );
	*((int *)(reference)) = 131;
	
	// Printing the values. Set the reference back to numbers
	reference = numbers;
	
	COUT << "Double:  " << *((double *)(reference)) << "\t at address " << reference << ENDL;
	
	reference = (void *) ( (double *)reference + sizeof(double) );
	COUT << "Float:   " << *((float *)(reference)) << "\t at address " << reference << ENDL;
	
	reference = (void *) ( (float *)reference + sizeof(float) );
	COUT << "Integer: " << *((int *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Address of numbers  : " << numbers << ENDL;
	COUT << "Address of reference: " << reference << ENDL;
	
	// Free void* with allocated memory
	free( numbers );

	return 0;
}
