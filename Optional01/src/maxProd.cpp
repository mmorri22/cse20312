#include "../include/DynArr.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray( DynArr<int>& theArray ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < theArray.length(); iter++){
		
		COUT << theArray[iter];
		
		if( iter < theArray.length() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}

int maxSubArrayDyn( DynArr<int>& theArray ) {
	
	int currMax = theArray[0];
	int globalMax = theArray[0];
	
	// Set first Negation to  
	bool firstNeg = ( theArray[0] < 0 );
	int numNeg = 0;
	int firstNegLoc = -1;
	
	if( firstNeg ){
		firstNegLoc = 0;
		numNeg = 1;
	}
		
	for(unsigned int iter = 1; iter < theArray.length(); iter++){
		
		COUT << theArray[iter] << " " << currMax << " " << globalMax << " " << firstNegLoc << " " << numNeg << ENDL;
		
		if(!firstNeg && theArray[iter] < 0){
			
			firstNeg = true;
			firstNegLoc = iter;
			
		}
		
		currMax *= theArray[iter];
		
		if( theArray[iter] < 0 ){
			
			if( numNeg > 2 && numNeg % 2 == 0 ){
				
				currMax /= theArray[firstNegLoc];
			}
			
			else if( numNeg > 2 && numNeg % 2 != 0 ){
				
				currMax *= theArray[firstNegLoc];
			}
			
			numNeg++;
			
		}
	
		if( currMax > globalMax ){
			
			globalMax = currMax;
		}
			
	}
	
	return globalMax;
	
}


int main(){
	
	// Create first array
	DynArr<int> array1;
	
	array1.push_back( -2 );		array1.push_back( 1 );
	array1.push_back( -3 );		array1.push_back( 4 );
	array1.push_back( -1 );		array1.push_back( 2 );
	array1.push_back( 1 );		array1.push_back( -5 );	
	array1.push_back( 4 );		array1.push_back( 1 );		
	
	
	printArray(array1);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayDyn(array1) << ENDL;
	
	array1.push_back( -10 );	
	printArray(array1);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayDyn(array1) << ENDL;	
	
	return 0;
}
