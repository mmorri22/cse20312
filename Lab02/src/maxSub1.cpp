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

int maxSubArrayBrute( DynArr<int>& theArray ) {
	
	int maxSize = -2147483648;		// Largest Negative 32 bit integer
		
	for(unsigned int iter = 0; iter < theArray.length(); iter++){
		
		int sum = theArray[iter];
		
		if(sum > maxSize){
			
			maxSize = sum;
		}
		
	}
	
	return maxSize;
	
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
	COUT << "Max Size = " << maxSubArrayBrute(array1) << ENDL;
	
	return 0;
}
