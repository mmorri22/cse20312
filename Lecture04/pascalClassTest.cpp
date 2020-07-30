/**********************************************
* File: pascalClassTest.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of a Class with allocated **array in C/C++
*
* Lecture 04 - Slide 49
**********************************************/

#include "pascalClass.h"

int main(void){
	
	// Get the number of levels for Pascal's Triangle 
	// and Create the Triangle class object
	COUT << "Testing original Pascal Tree:" << ENDL;
	Pascal theTree = getPascalTree();
	
	// Print the generated Triangle to the user 
	COUT << theTree << ENDL;
	
	// Run the interactive portion of the program
	runTests( theTree );

	// Test the Copy Constructor
	Pascal tree2( theTree );
	
	// Print the generated Triangle to the user 
	COUT << "Testing Copy Constructor Tree:" << ENDL;
	COUT << tree2 << ENDL;
	
	// Run the interactive portion of the program
	runTests( tree2 );
	
	// Test the Assignment Operator
	Pascal tree3 = theTree ;
	
	// Print the generated Triangle to the user 
	COUT << "Testing Assignment Operator Tree:" << ENDL;
	COUT << tree3 << ENDL;
	
	// Run the interactive portion of the program
	runTests( tree3 );

	// When the Pascal object goes out of scope 
	// The Destructor is automatically called
	// No need to do anything
	
	return 0;
}