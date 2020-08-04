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
	
	COUT << "currMax = " << currMax << ENDL;
		
	for(unsigned int iter = 1; iter < theArray.length(); iter++){
		
		// Get the intermediate sum
		int sum = theArray[iter] + currMax;
		
		// Select the current Max
		if( sum > theArray[iter] ){
			
			currMax = sum;
		}
		else{
			
			currMax = theArray[iter];
		}
		
		// Print intermediate results
		COUT << "theArray[" << iter << "] = " << theArray[iter]; 
		COUT << ", Sum = " << sum;
		COUT << ", currMax = " << currMax << ENDL;
		
	}
	
	return currMax;
	
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
	
	
	// Create first array
	DynArr<int> array2;	
	array2.push_back( 22 );		array2.push_back( 50 );
	array2.push_back( -8 );		array2.push_back( 46 );
	array2.push_back( -5 );		array2.push_back( 9 );
	array2.push_back( 8 );		array2.push_back( -1 );	
	array2.push_back( 2 );		array2.push_back( -1 );	

	printArray(array2);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayDyn(array2) << ENDL;
	
	return 0;
}
