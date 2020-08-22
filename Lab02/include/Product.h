#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray( std::vector<int>& theArray ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray[iter];
		
		if( iter < theArray.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}


std::vector<int> solveArray( std::vector<int>& theArray ){

	// Create an array to store the solution
	std::vector<int> solution( theArray.size() );
	
	// Forward Iteration
	solution[ 0 ] = 1;
	for(unsigned int iter = 1; iter < theArray.size(); iter++){
		
		solution[ iter ] = solution[ iter - 1 ] * theArray[ iter - 1 ];
	
	}
	
	// Create a reverse value for the multiplication
	int tempBackward = 1;
	for(long unsigned int iter = theArray.size() - 1; iter > 0; iter--){
		
		tempBackward *= theArray[iter];
		
		solution[iter - 1] *= tempBackward;
		
	}
	
	return solution;
	
}

void runSolution( std::vector<int>& theArray ) {
	
	// Print the Initial Input
	COUT << "Input : ";
	printArray( theArray );
	COUT << "\n";

	// Run the Solution and Print the Output
	COUT << "Output: ";
	std::vector<int> solution = solveArray( theArray );
	printArray( solution );
	COUT << ENDL << ENDL;	
	
}



#endif