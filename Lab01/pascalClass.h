/**********************************************
* File: pascalClass.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of a Class with allocated **array in C/C++
*
* Lecture 04 - Slide 30, 34, 36, 37, 42, 45, 47
**********************************************/

#ifndef PASCALCLASS_H
#define PASCALCLASS_H

#include <iostream>
#include <cstdlib>

// You will learn about #define in Lab 1
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

// Students learn what a type definition is
typedef unsigned int UINT;

class Pascal{
	
	private:
	
		UINT numLevels;		// Number of levels 
		UINT** pascalTri;	// Actual Pascal Triangle
		
		void createTree();
		
	public:
	
		Pascal( UINT numLevIn );
		
		~Pascal();
		
		Pascal( const Pascal& copy );
		
		Pascal& operator=( const Pascal& rhs );
		
		void printValue( UINT row, UINT col ) const;
		
		friend std::ostream& operator<<( std::ostream& ifstream, const Pascal& printPas );

};

// Get the number of levels from the user
Pascal getPascalTree();

// Run the inputs from the user of Pascal's Triangle of numLevels height
void runTests( const Pascal& theTree );

#endif