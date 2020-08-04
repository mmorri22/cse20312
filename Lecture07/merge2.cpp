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

void merge(int* array, int min, int max){
	
	
	if(max > min + 1){
		
		COUT << "LEFT : " << min << " " << (min + max) / 2; 
		COUT << ", RIGHT: " << (min + max) / 2 + 1 << " " << max << ENDL;
		merge(array, min, (min + max) / 2);
 		merge(array, (min + max) / 2 + 1, max);
		
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
	
	/* Initialize the sort */
	COUT << "Sorting array1... " << ENDL;
	merge(array1, 0, length1 - 1);
	
	COUT << "Sorting array2... " << ENDL;
	merge(array2, 0, length2 - 1);
	
	return 0;
	
}