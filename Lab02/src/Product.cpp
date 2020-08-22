#include "../include/Product.h"

int main(){
	
	int numVals = 5;
	
	// Create first array
	std::vector<int> array1( numVals );
	
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;
	array1[3] = 4;
	array1[4] = 5;
	
	runSolution(array1);
	
	// Create second array
	
	std::vector<int> array2( numVals - 1);
	
	array2[0] = 1;
	array2[1] = 2;
	array2[2] = 3;
	array2[3] = 4;
	
	runSolution(array2);
	
	// Create third array 
	
	std::vector<int> array3( numVals + 1);
	
	array3[0] = 22;
	array3[1] = 18;
	array3[2] = 5;
	array3[3] = 33;
	array3[4] = 9;
	array3[5] = 101;
	
	runSolution(array3);
	
	return 0;
}
