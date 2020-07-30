/**********************************************
* File: array.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of different length arrays, sizeof, and template function
*
* Lecture 04 - Slides 13-14
**********************************************/

#include <iostream>
#include <cstdlib>

// No Global Variable

// Print int array of size 
template< class T >
void printArray(T array[], long unsigned int arraySize)
{
	for(long unsigned int iter = 0; iter < arraySize; iter++ ){
		
		// Print array element using pointer arithmetic
		std::cout << *(array + iter) << " ";
	}
	std::cout << std::endl;
	
}

int main(){
	
	// Brace Initializer Lists
	int arrayInt[] = {31, 41, 59, 26, 53, 58, 97, 93, 1842}; 
	
	// Get the size of the array
	long unsigned int arrayIntSize = sizeof(arrayInt)/sizeof(int); 
	
	// Print the Array
	printArray(arrayInt, arrayIntSize);
	
	// Initialze Char Array Size
	char arrayChar[] = {'N', 'o', 't', 'r', 'e', ' ', 'D', 'a', 'm', 'e'};
	
	// Get the size of the array
	long unsigned int arrayCharSize = sizeof(arrayChar)/sizeof(char); 
	
	// Print the Array
	printArray(arrayChar, arrayCharSize);

	return 0;
}