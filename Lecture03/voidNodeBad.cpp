/**********************************************
* File: voidNodeBad.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating different types using the
* same void pointer. We store and print 
* a double and a float and an int
*
* Shows void pointers as "Pass by reference"
*
* Prints the elements in the wrong order, so the
* double, float, and int print the wrong values to
* the screen even though the data is structured 
* correctly on the heap.
*
* Lecture 3 - Slides 10
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

void setNodeValues( void* reference, double theDbl, float theFlt, int theInt ){
	
	// Put a double in the first 64 bits after reference
	*((double *)(reference)) = theDbl;
	
	// Move past 64 bits and put in a float 
	reference = (void *) ( (double *)reference + sizeof(double) );
	*((float *)(reference)) = theFlt;
	
	// Move past 32 bits and put in an integer
	reference = (void *) ( (float *)reference + sizeof(float) );
	*((int *)(reference)) = theInt;	
	
}


void printNodeValues( void* reference ){
	
	COUT << "-----------------------------" << ENDL;
	COUT << "Initial address of reference: " << reference << ENDL << ENDL;	
	
	// Deliberate logic error - Print 32 bits of int where a double was placed 
	COUT << "Int:  " << *((int *)(reference)) << "\t at address " << reference << ENDL;
	
	// Deliberate Logic Error - Adding 32 bits instead of 64 - Printing float
	reference = (void *) ( (int *)reference + sizeof(int) );
	COUT << "Float:   " << *((float *)(reference)) << "\t at address " << reference << ENDL;
	
	// Deliberate logic error - Printing double where float and int were placed
	reference = (void *) ( (float *)reference + sizeof(float) );
	COUT << "Double: " << *((double *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Final sddress of reference: " << reference << ENDL;	
	
}

int main(void){
	
	long unsigned int nodeSize = sizeof(double) + sizeof(float) + sizeof(int);
	
	void* node1 = malloc( nodeSize );
	void* node2 = malloc( nodeSize );
	
	// Set the node Values for node1 
	setNodeValues( node1, -0.625, (float)1.5625, 131 );
	
	// Set the node Values for node2 
	setNodeValues( node2, -34.77, (float)44.96, 1842 );
	
	// Printing the values. Set the reference back to numbers
	printNodeValues( node1 );
	printNodeValues( node2 );
	
	// Free void* with allocated memory
	free( node1 );
	free( node2 );

	return 0;
}
