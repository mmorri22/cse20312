#ifndef SOL2_H
#define SOL2_H

#include "DynArr.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray(const DynArr<int>& array){
	
	COUT << "Input: [";
	
	for(unsigned int iter = 0; iter < array.length(); iter++){
		
		COUT << array[iter];
		
		if( iter < array.length() - 1){
			
			COUT << ",";
		}
		
	}
	
	COUT << "]" << ENDL;
	
}

void findSolution(const DynArr<int>& array){
	
	int minimumLoc = -1;
	int minumumVal = 2147483647; // Largest Signed Int Possible
	
	for(unsigned int iter = 0; iter < array.length(); iter++){

		if( array[iter] < minumumVal ){
			
			minimumLoc = iter;
			minumumVal = array[iter];
		}

	}
	
	COUT << "Minimum is at " << minimumLoc << ", value is " << array[minimumLoc] << ENDL;

}

#endif