/**********************************************
* File: pascal.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Function definitions to complete the Pascal 
* Triangle
*
* Lecture 04 - Slide 21, 25-27
**********************************************/

#include "pascal.h"

unsigned int getNumLevels(){
	
	unsigned int numLevels;
	
	COUT << "How many levels do you want to calculate: ";
	
	CIN >> numLevels;
	
	return numLevels;
	
}

unsigned int** createPascal(unsigned int numLevels){
	
	// Allocate the number of int** pointers 
	unsigned int** pascalTri = (unsigned int**)malloc(numLevels * sizeof(unsigned int*));

	// Go through each pointer
	for (unsigned int currRow = 0; currRow < numLevels; currRow++ ){
		
		// Create an array with currRow plus one elements
		pascalTri[currRow] = (unsigned int*)malloc( (currRow + 1) * sizeof(unsigned int) );

		// Set the first number 
		pascalTri[currRow][0] = 1;
		
		// For the middle numbers 
		if (currRow >= 2){
			
			for(unsigned int number = 1; number < currRow; number++){
				
				pascalTri[currRow][number] = pascalTri[currRow - 1][number - 1] + pascalTri[currRow - 1][number];
				
			}
		}
		// the last number
		pascalTri[currRow][currRow] = 1;
	}

	return pascalTri;
}

void printPascal( unsigned int** pascalTri, unsigned int numLevels ){
	
	COUT << ENDL << "Generated Pascal's Triangle..." << ENDL;
	
	// Go through each pointer
	for (unsigned int i_row = 0; i_row < numLevels; i_row++ ){
		
		for (unsigned int j_row = 0; j_row <= i_row; j_row++ ){
			
			COUT << pascalTri[i_row][j_row] << " ";
		}
		COUT << ENDL;
	}
	COUT << ENDL;
}


void runTests( unsigned int** pascalTri, unsigned int numLevels ) {
	
	char contLoop = 'y';
	// extract a specific element
	
	while ( contLoop == 'y' ){
		
		// Get the row and column
		unsigned int row, column;
		
		COUT << "Enter a row and column value to print [two number only]: ";
		CIN >> row >> column;
		
		// If row - 1 is greater than numLevels, you are invalid
		if (row > numLevels){
			COUT << row << " is not a valid row" << ENDL;
		}
		
		// The column - 1 cannot exceed the current row
		else if (column - 1 > row - 1){
			COUT << column << " is not a valid column in row " << row << ENDL;
		}
		
		// If we get here, we can access the elements without issue
		else {
			COUT << pascalTri[row - 1][column - 1] << ENDL;
		}
		
		// Get the next element from the user 
		COUT << "Continue? [y/n]: ";
		CIN >> contLoop;
		COUT << ENDL;
	}
	
	COUT << "Exiting program..." << ENDL;	
}

// Example of freeing memory of arrays of arrays 
void freePascal( unsigned int** pascalTri, unsigned int numLevels ){
	
	// Free the individual arrays first
	for (unsigned int i_row = 0; i_row < numLevels; i_row++ ){
		
		free( pascalTri[i_row] );
		
	}
	
	// Finally, free the int** pointers themselves 
	free( pascalTri );
	
}