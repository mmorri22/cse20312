#include <iostream>
#include <sstream>

#include "../include/LinearProbe.h"

double Fib(int n, HashTable<int, double>& fibVals){

	/* If the Hash contains the value, just return */
	if(fibVals.contains(n))
		return fibVals[n];
	
	/* Base Cases for Fibonacci */
	if(n == 0 || n == 1){
		fibVals.insert( {n, 1} );
		return 1;
	}
	
	/* Insert the value into the Hash Table */
	fibVals.insert( {n, Fib(n-1, fibVals) + Fib(n-2, fibVals)} );
	
	return fibVals[n];
	
}

int main(int argc, char**argv){
	
	if(argc != 2){
		std::cerr << "Incorrect Number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	int factNum;
	std::stringstream convert(argv[1]);

	//give the value to factNum using the characters in the string
	if ( !(convert >> factNum) ){
		std::cerr << "Not a valid input" << std::endl;
		exit(-1);
	}
	
	/* Create the Memoization Hash Table */
	HashTable<int, double> fibVals;
	
	/* Call the recursive function */
	std::cout << Fib( factNum, fibVals ) << std::endl;
	return 0;
	
}
