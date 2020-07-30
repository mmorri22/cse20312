/**********************************************
* File: voidTypes2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating different types using the
* same void pointer. We store and print 
* a double and a float.
*
* Lecture 3 - Slides 5-7
**********************************************/

#include <iostream>
#include <cstdlib>
#define COUT std::cout
#define ENDL std::endl

int main(void){
	
	void* numbers = malloc( sizeof(double) + sizeof(float) );
	void* reference = numbers;
	
	// Put a double in the first 64 bits after reference
	*((double *)(reference)) = -0.625;
	
	// Move past 64 bits and put in a float 
	reference += sizeof(double);
	*((float *)(reference)) = 1.5625;
	
	// Printing the values. Set the reference back to numbers
	reference = numbers;
	
	COUT << "Double:  " << *((double *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(double);
	COUT << "Float:   " << *((float *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Address of numbers  : " << numbers << ENDL;
	COUT << "Address of reference: " << reference << ENDL;
	
	// Free void* with allocated memory
	free( numbers );

	return 0;
}
