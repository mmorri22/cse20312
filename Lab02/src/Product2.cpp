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

std::vector<int> solveArray( std::vector<int>& theArray ){
	
	// Create an array to store the solution
	std::vector<int> solution( theArray.size() );
	
	// Forward Iteration
	solution[ 0 ] = 1;
	for(unsigned int iter = 1; iter < theArray.size(); iter++){
		
		solution[ iter ] = solution[ iter - 1 ] * theArray[ iter - 1 ];
	
	}
	
	return solution;
}


int main(){
	
	int numVals = 5;
	
	// Create first array
	std::vector<int> array1( numVals );
	
	array1[0] = 1; 	array1[1] = 2;
	array1[2] = 3; 	array1[3] = 4;
	array1[4] = 5;
	
	printArray(array1);
	COUT << ENDL;
	
	std::vector<int> solution1 = solveArray( array1 );
	printArray( solution1 );
	COUT << ENDL;
	
	// Create second array
	
	std::vector<int> array2( numVals - 1 );
	
	array2[0] = 1; 	array2[1] = 2;
	array2[2] = 3; 	array2[3] = 4;
	
	printArray(array2);
	COUT << ENDL;
	
	std::vector<int> solution2 = solveArray( array2 );
	printArray( solution2 );
	COUT << ENDL;
	
	// Create third array 
	
	std::vector<int> array3( numVals + 1);
	
	array3[0] = 22; array3[1] = 18;
	array3[2] = 5; 	array3[3] = 33;
	array3[4] = 9;	array3[5] = 101;
	
	printArray(array3);
	COUT << ENDL;
	
	std::vector<int> solution3 = solveArray( array3 );
	printArray( solution3 );
	COUT << ENDL;
	
	return 0;
}
