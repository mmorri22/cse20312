#include <iostream>
#include <cstdlib>

const int length1 = 8;
const int length2 = 9;

#define COUT std::cout
#define ENDL std::endl

template <class T>
void printArray(T* array, const int& length){
	
	for(int iter = 0; iter < length; iter++){
		
		COUT << *(array + iter) << " ";
		
	}
	
}

template <class T>
void merge(T* array, int min, int max){
	
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
		
			T temp = array[max];
			array[ max ] = array [ min ];
			array[ min ] = temp;
		
		}
		
	}
	
	/* Subarray longer than two elements */
	else{
		
		int start1 = min;
		int start2 = (min + max) / 2 + 1;
		
		// Create tempArray
		T* arrayTemp = (T *)malloc( sizeof(T) * ( max - min ) );
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
		
	}

}

int main(){
	
	/* Array of odd length */
	int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};
	
	char array2[length2] = {'A', 'q', 'R', '!', 'v', 'a', 'Q', 's', '?'};
	
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