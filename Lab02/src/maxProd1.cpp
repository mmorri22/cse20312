#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray( std::vector<int>& theArray ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray[iter];
		
		if( iter < theArray.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}

int maxSubArrayBrute( std::vector<int>& theArray ) {
	
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
	std::vector<int> array1;
	
	array1.push_back( -2 );		array1.push_back( 1 );
	array1.push_back( -3 );		array1.push_back( 4 );
	array1.push_back( -1 );		array1.push_back( 2 );
	array1.push_back( 1 );		array1.push_back( -5 );	
	array1.push_back( 4 );		array1.push_back( 1 );		
	
	
	printArray(array1);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array1) << ENDL;
	
	array1.push_back( -10 );	
	printArray(array1);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(array1) << ENDL;	
	
	return 0;
}
