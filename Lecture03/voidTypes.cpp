/**********************************************
* File: voidTypes.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating different types using the
* same void pointer. First, we store and print 
* a double only.
*
* Lecture 3 - Slide 4
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main(void){
	
	void* numbers = malloc( sizeof(double) );
	void* reference = numbers;
	
	// Put a double in the first 64 bits after reference
	*((double *)(reference)) = -0.625;
	
	// Printing the values. Set the reference back to numbers
	reference = numbers;
	
	COUT << "Double:  " << *((double *)(reference)); 
	COUT << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Address of numbers  : " << numbers << ENDL;
	COUT << "Address of reference: " << reference << ENDL;
	
	// Free void* with allocated memory
	free( numbers );

	return 0;
}
