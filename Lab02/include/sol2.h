#ifndef SOL2_H
#define SOL2_H

#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray(const std::vector<int>& array){
	
	COUT << "Input: [";
	
	for(unsigned int iter = 0; iter < array.size(); iter++){
		
		COUT << array[iter];
		
		if( iter < array.size() - 1){
			
			COUT << ",";
		}
		
	}
	
	COUT << "]" << ENDL;
	
}

void findSolution(const std::vector<int>& array){
	
	int minimumLoc = -1;
	int minumumVal = 2147483647; // Largest Signed Int Possible
	
	for(unsigned int iter = 0; iter < array.size(); iter++){

		if( array[iter] < minumumVal ){
			
			minimumLoc = iter;
			minumumVal = array[iter];
		}

	}
	
	COUT << "Minimum is at " << minimumLoc << ", value is " << array[minimumLoc] << ENDL;

}

#endif