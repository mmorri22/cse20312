/**********************************************
* File: voidNodeBad2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating multiple version of data 
* with different types of elements
*
* Shows void pointers as "Pass by reference"
*
* This code will run correctly. However, the setNodeValues 
* is out of order, which makes the pointer arithmetic 
* more complex, reducing the efficiency of the code 
*
* Lecture 02 - Part 2 - Slide 21
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

void setNodeValues( void* reference, double theDbl, float theFlt, int theInt ){
	
	// Skip to the int first 
	reference += sizeof(double);
	reference += sizeof(float);
	*((int *)(reference)) = theInt;	
	
	// Skip back to the double 
	reference -= sizeof(float);
	reference -= sizeof(double);
	*((double *)(reference)) = theDbl;
	
	// Move past 32 bits and put in an integer
	reference += sizeof(double);
	*((float *)(reference)) = theFlt;
	
}


void printNodeValues( void* reference ){
	
	COUT << "-----------------------------" << ENDL;
	COUT << "Initial address of reference: " << reference << ENDL << ENDL;	
	
	COUT << "Double:  " << *((double *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(double);
	COUT << "Float:   " << *((float *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(int);
	COUT << "Integer: " << *((int *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Final sddress of reference: " << reference << ENDL;	
	
}

int main(void){
	
	long unsigned int nodeSize = sizeof(double) + sizeof(float) + sizeof(int);
	
	void* node1 = malloc( nodeSize );
	void* node2 = malloc( nodeSize );
	
	// Set the node Values for node1 
	setNodeValues( node1, -0.625, 1.5625, 131 );
	
	// Set the node Values for node2 
	setNodeValues( node2, -34.77, 44.96, 1842 );
	
	// Printing the values. Set the reference back to numbers
	printNodeValues( node1 );
	printNodeValues( node2 );
	
	// Free void* with allocated memory
	free( node1 );
	free( node2 );

	return 0;
}
