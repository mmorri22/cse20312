/**********************************************
* File: pascalTest.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Reviewing the use of Header Files in C/C++
*
* Lecture 04 - Slide 27-28
**********************************************/

#include "pascal.h"

int main(void){
	
	// Get the number of levels for Pascal's Triangle
	unsigned int numLevels = getNumLevels();
	
	// Create the Triangle
	unsigned int** pascalTri = createPascal(numLevels);
	
	// Print the generated Triangle to the user 
	printPascal( pascalTri, numLevels );
	
	// Run the interactive portion of the program
	runTests( pascalTri, numLevels );

	// Free the memory for the Pascal Triangle
	freePascal( pascalTri, numLevels );

	return 0;
}
