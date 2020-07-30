/**********************************************
* File: array.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Simple example of an array and a #define global variable
*
* Lecture 04 - Slides 11-12
**********************************************/

#include <iostream>
#include <cstdlib>

// M length array
#define M 10

void printMatrix(int matrix[M])
{
	for(unsigned int iter = 0; iter < M; iter++ ){
		
		std::cout << matrix[iter] << " ";
	}
	std::cout << std::endl;
	
}

int main(){
	
	// Brace Initializer Lists
	int matrix[] = { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 };
	
	printMatrix(matrix);

	return 0;
	
}