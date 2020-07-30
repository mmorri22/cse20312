/**********************************************
* File: pascalClass.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of a Class with allocated **array in C/C++
*
* Lecture 04 - Slide 32, 33, 34, 36, 37, 42, 46-48
**********************************************/

#include "pascalClass.h"

// Private Method to Build the Tree
void Pascal::createTree(){
	
	// Go through each pointer
	for (UINT currRow = 0; currRow < numLevels; currRow++ ){
		
		// Create an array with currRow plus one elements
		pascalTri[currRow] = ( UINT* )malloc( (currRow + 1) * sizeof(UINT) );

		// Set the first number 
		pascalTri[currRow][0] = 1;
		
		// For the middle numbers 
		if (currRow >= 2){
			
			for(UINT number = 1; number < currRow; number++){
				
				pascalTri[currRow][number] = pascalTri[currRow - 1][number - 1] + pascalTri[currRow - 1][number];
			}
		}
		// the last number
		pascalTri[currRow][currRow] = 1;
		
	}		
}

// This code is identical to the function createPascal in pascal.cpp
Pascal::Pascal( UINT numLevIn ) : numLevels( numLevIn ), 
			pascalTri( (UINT **)malloc( numLevels * sizeof( UINT * ) ) ) { 

	createTree();
			
}

// Destructor is Equivalent to freePascal in pascal.cpp
Pascal::~Pascal(){
	
	// Free the individual arrays first
	for (UINT i_row = 0; i_row < numLevels; i_row++ ){
		
		free( pascalTri[i_row] );
		
	}
	
	// Finally, free the int** pointers themselves 
	free( pascalTri );	
	
}

// Copy Constructor
Pascal::Pascal( const Pascal& copy ) : numLevels( copy.numLevels ), 
			pascalTri( (UINT **)malloc( numLevels * sizeof( UINT * ) ) ){
	
	createTree();
	
}

Pascal& Pascal::operator=( const Pascal& rhs ){
	
	// Check if this != address of rhs to save time on a = a scenario
	if( this != &rhs ){
		
		this->numLevels = rhs.numLevels;
		this->createTree();
		
	}
	return *this;
}

void Pascal::printValue( UINT row, UINT column ) const{
	
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
	
}

std::ostream& operator<<( std::ostream& out, const Pascal& printPas ){
	
	out << ENDL << "Generated Pascal's Triangle..." << ENDL;
	
	// Go through each pointer
	for (UINT i_row = 0; i_row < printPas.numLevels; i_row++ ){
		
		// The row will contain i_row elements
		for (UINT j_row = 0; j_row <= i_row; j_row++ ){
			
			// Print the specific element
			out << printPas.pascalTri[i_row][j_row] << " ";
		}
		out << ENDL;
	}
	out << ENDL;	
	
	return out;
}

Pascal getPascalTree(){
	
	UINT numLevels;
	
	COUT << "How many levels do you want to calculate: ";
	
	CIN >> numLevels;
	
	return Pascal(numLevels);
	
}


void runTests( const Pascal& theTree ) {
	
	char contLoop = 'y';
	// extract a specific element
	
	while ( contLoop == 'y' ){
		
		// Get the row and column
		UINT row, column;
		
		COUT << "Enter a row and column value to print [two number only]: ";
		CIN >> row >> column;
		
		// Print the value from the tree
		theTree.printValue( row, column );
		
		// Get the next element from the user 
		COUT << "Continue? [y/n]: ";
		CIN >> contLoop;
		COUT << ENDL;
	}
	
	COUT << "Exiting program..." << ENDL;	
}