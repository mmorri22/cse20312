#include <iostream>
#include <cstdlib>

const int length1 = 8;
const int length2 = 9;

#define COUT std::cout
#define ENDL std::endl

void printArray(int* array, const int& length){
	
	for(int iter = 0; iter < length; iter++){
		
		COUT << *(array + iter) << " ";
		
	}
	
}


int main(){
	
	/* Array of odd length */
	int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};
	
	int array2[length2] = {14, 99, 42, 77, 2, 66, 1, 8, 44};
	
	/* Print the initiali arrays */
	COUT << "Initial Array 1: ";
	printArray(array1, length1);
	COUT << ENDL;
	
	COUT << "Initial Array 2: ";
	printArray(array2, length2);
	COUT << ENDL;
	
	return 0;
	
}