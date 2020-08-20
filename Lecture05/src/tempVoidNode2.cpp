/**********************************************
* File: tempVoidNode.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of allocating different types using the
* same void pointer. We store and print 
* a double and a float and an int
*
* Shows void pointers as "Pass by reference"
* and modularity
*
* Does not print the right values due to improper casting
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

template<class T, class U, class V>
void setNodeValues( void* reference, T firstVar, U secondVar, V thirdVar ){
	
	// Put a T in the first 64 bits after reference
	*((T *)(reference)) = firstVar;
	
	// Move past 64 bits and put in a float 
	reference += sizeof(T);
	*((U *)(reference)) = secondVar;
	
	// Move past 32 bits and put in an integer
	reference += sizeof(U);
	*((V *)(reference)) = thirdVar;	
	
}

template<class T, class U, class V>
void printNodeValues( void* reference ){
	
	COUT << "-----------------------------" << ENDL;
	COUT << "Initial address of reference: " << reference << ENDL << ENDL;	
	
	COUT << "First:  " << *((T *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(T);
	COUT << "Second:   " << *((U *)(reference)) << "\t at address " << reference << ENDL;
	
	reference += sizeof(U);
	COUT << "Third: " << *((V *)(reference)) << "\t at address " << reference << ENDL;
	
	COUT << ENDL;
	COUT << "Final sddress of reference: " << reference << ENDL;	
	
}

int main(void){
	
	long unsigned int nodeSize = sizeof(double) + sizeof(float) + sizeof(long int);
	
	void* node1 = malloc( nodeSize );
	void* node2 = malloc( nodeSize );
	
	// Set the node Values for node1 
	setNodeValues( node1, -0.625, (float)1.5625, (long int)131 );
	
	// Set the node Values for node2 
	setNodeValues( node2, -34.77, (float)44.96, (long int)1842 );
	
	// Printing the values. Set the reference back to numbers
	printNodeValues<double, float, long int>( node1 );
	printNodeValues<double, float, long int>( node2 );
	
	// Free void* with allocated memory
	free( node1 );
	free( node2 );

	return 0;
}
