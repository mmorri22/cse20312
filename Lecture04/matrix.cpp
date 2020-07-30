/**********************************************
* File: matrix.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Using OOP, simpler version of allocating the 
* matrix if you know the elements in advance 
* compared to procMatrix.cpp
*
* Lecture 04 - Slide 18-19
**********************************************/

#include <iostream>
#include <cstdlib>

// M x N matrix
#define M 10
#define N 10

void printMatrix(int matrix[][N])
{
	for(unsigned int iter = 0; iter < M; iter++ ){
		
		for(unsigned int jter = 0; jter < M; jter++ ){
			std::cout << matrix[iter][jter] << " ";
		}
		std::cout << std::endl;
	}
	
}

int main(){
	
	// Brace Initializer Lists
	int matrix[M][N] =
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 }
	}; 
	
	printMatrix(matrix);

	return 0;
	
}