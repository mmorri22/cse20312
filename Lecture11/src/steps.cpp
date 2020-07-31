#include <iostream>
#include <sstream>

#include "../include/LinearProbe.h"

double steps(int n, HashTable<int, double>& stepVals){

	/* If the Hash contains the value, just return */
	if(stepVals.contains(n))
		return stepVals[n];
	
	/* Base Cases for Steps */
	if(n <= 0 ){
		return 0;
	}
	else if(n == 1){
		stepVals.insert( {n, 1} );
		return 1;
	}
	else if(n == 2){
		stepVals.insert( {n, 2} );
		return 2;
	}
	
	/* Insert the value into the Hash Table */
	stepVals.insert( {n, steps(n-1, stepVals) + steps(n-2, stepVals) + steps(n-3, stepVals)} );
	
	return stepVals[n];
	
}

int main(int argc, char**argv){
	
	if(argc != 2){
		std::cerr << "Incorrect Number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	int stepNum;
	std::stringstream convert(argv[1]);

	//give the value to stepNum using the characters in the string
	if ( !(convert >> stepNum) ){
		std::cerr << "Not a valid input" << std::endl;
		exit(-1);
	}
	
	/* Create the Memoization Hash Table */
	HashTable<int, double> stepVals;
	
	/* Call the recursive function */
	std::cout << steps( stepNum, stepVals ) << std::endl;
	return 0;
	
}
