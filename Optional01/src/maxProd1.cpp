#include "../include/DynArr.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int maxSubArrayBrute( DynArr<int>& theArray ) {
	
	int maxSize = -2147483648;		// Largest Negative 32 bit integer
		
	for(unsigned int iter = 0; iter < theArray.size(); iter++){
		
		int sum = theArray[iter];
		
		if(sum > maxSize){
			
			maxSize = sum;
		}
		
		// Modified from maxSub1.cpp - Adding the sub array iteration
		for(unsigned int jter = iter + 1; jter < theArray.size(); jter++){
			
			sum *= theArray[jter];
			
			if(sum > maxSize){
				
				maxSize = sum;
			}			
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
	
	COUT << array1 << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array1) << ENDL;
	
	array1.push_back( -10 );	
	COUT << ENDL;
	COUT << array1 << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array1) << ENDL;	
	

	// 10, 35, -2, 18, -10, -5, 100

	DynArr<int> array2;
	array2.push_back( 10 );		array2.push_back( 32 );
	array2.push_back( -2 );		array2.push_back( 18 );
	array2.push_back( -10 );	array2.push_back( -5 );
	array2.push_back( 100 );	
	
	COUT << ENDL;
	COUT << array2 << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array2) << ENDL << ENDL;
	
	// Replace 18 with 0
	array2[ 3 ] = 0;
	COUT << ENDL;
	COUT << array2 << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array2) << ENDL << ENDL;
	
	return 0;
}
