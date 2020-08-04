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
	
	/* Binary Recursion */
	if(max > min + 1){
		
		merge(array, min, (min + max) / 2);
 		merge(array, (min + max) / 2 + 1, max);
		
	}
	
	/* If min == max, no need to sort, since only 1 element */
	if(min == max)
		return;
	
	/* Sort Sub Array */
	else if( max == min + 1 ) {
		
		if( array[max] < array[ min ] ){
		
			int temp = array[max];
			array[ max ] = array [ min ];
			array[ min ] = temp;
		
		}
		
	}
	
	/* Subarray longer than two elements */
	else{
		
		int start1 = min;
		int start2 = (min + max) / 2 + 1;
		
		COUT << "Min = " << start1 << ", Mid = " << start2 << ", Max = " << max << ENDL;
		
		COUT << "Initial Subarray: ";
		for(int iter = min; iter <= max; iter++ ){
			
			COUT << array[iter] << " ";
		}
		COUT << ENDL;
		
		// Create tempArray
		int* arrayTemp = (int *)malloc( sizeof(int) * ( max - min ) );
		int arrayIter = 0;
		
		while( start1 <= (min + max) / 2 && start2 <= max ){
			
			if( array[start1] >= array[start2] ){
				
				arrayTemp[arrayIter] = array[start2];
				start2++;
				
			}
			else{
				
				arrayTemp[arrayIter] = array[start1];
				start1++;
			}
			arrayIter++;
		}
		
		while( start1 <= (min + max) / 2 ){
			
				arrayTemp[arrayIter] = array[start1];
				start1++; arrayIter++;
				
		}

		while( start2 <= max ){
			
				arrayTemp[arrayIter] = array[start2];
				start2++; arrayIter++;
				
		}
		
		for(int updateIter = 0; updateIter < arrayIter; updateIter++){
			
			array[min + updateIter] = arrayTemp[updateIter];
			
		}
		
		COUT << "Sorted Subarray: ";
		for(int iter = min; iter <= max; iter++ ){
			
			COUT << array[iter] << " ";
		}
		COUT << ENDL << ENDL;
		
	}

}

int main(){
	
	/* Array of odd length */
	int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};
	
	int array2[length2] = {14, 99, 42, 77, 2, 66, 1, 8, 44};
	
	/* Print the initial arrays */
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
	
	/* Print the final arrays */
	COUT << "Final Array 1: ";
	printArray(array1, length1);
	COUT << ENDL;
	
	COUT << "Final Array 2: ";
	printArray(array2, length2);
	COUT << ENDL;
	
	return 0;
	
}