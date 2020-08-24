#ifndef SOL3_H
#define SOL3_H

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
	
	int nextLocation = -1;
	int nextLargest = -1;	// Smallest Value
	
	// Current Maximum Values
	int maxLocation = -1;
	int nextMaxLocation = -1;
	int maxValue = -1;
	
	for(unsigned int iter = 0; iter < array.size(); iter++){

		if( array[iter] < minumumVal ){
			
			minimumLoc = iter;
			minumumVal = array[iter];
			
			// The largest should NOT be before the minimum location
			nextLocation = iter;
			nextLargest = array[iter];
			
		}
		
		// If the next location is not the smallest
		// AND if the value is bigger tha
		else if (array[iter] > nextLargest){
			
			nextLocation = iter;
			maxLocation = array[iter];
			
			// Check if the newest largest is 
			if( maxLocation == -1 ){
				
				maxLocation = nextLocation
				nextMaxLocation = maxLocation;
				maxValue = array[maxLocation];
			}
			
		}

	}
	
	COUT << "Minimum is at " << minimumLoc << ", value is " << array[minimumLoc] << ENDL;
	COUT << "Next largest: " << nextLocation << ", value is " << array[nextLocation] << ENDL;

}

#endif