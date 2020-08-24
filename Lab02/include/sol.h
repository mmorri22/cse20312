#ifndef SOL_H
#define SOL_H

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
	int compMin = -1;
	int compMax = -1;
			
	
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
			nextLargest = array[iter];
			
		}
		
		// Keeping track of the largest difference
		if( compMin == -1 ){
			compMin = iter;
			compMax = iter;				
		}
		else{
			
			if( nextLargest - minumumVal >= array[compMax] - array[compMin] ){
				
				compMax = nextLocation;
				compMin = minimumLoc;
			}
		}
	}
	
	// Print the output stock 
	COUT << "Stock: " << array[compMax] - array[compMin] << ENDL; 
	
	// If minimumLoc == nextLocation, then we did not find a good stock
	if( compMin == compMax ){
		
		COUT << "Explanation: In this case, no transaction is done, i.e. max profit = 0." << ENDL;
		
	}
	
	else{
		
		COUT << "Explanation: Sell at " << compMax << " when stock is " << array[compMax] << ENDL;
		COUT << "             Buy at " << compMin << " when stock is " << array[compMin] << ENDL;
		
	}

}

#endif