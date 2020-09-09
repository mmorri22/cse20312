/**********************************************
* File: bucketSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This program uses a Sorted Dynamic Array to
* implement the Bucket Sort Algorithm
**********************************************/

#include <iostream>
#include "../include/SorDynArr.h"

int main(){

	long unsigned int numBuckets = 10;
	SorDynArr<int>* buckets = new SorDynArr<int>[ numBuckets ];

	// Create an array of initial elements
	int* initialVals = new int[11];
	initialVals[0] = 78; initialVals[1] = 17; initialVals[2] = 39;
	initialVals[3] = 26; initialVals[4] = 72; initialVals[5] = 94;
	initialVals[6] = 21; initialVals[7] = 12; initialVals[8] = 23;
	initialVals[9] = 68; initialVals[10] = 76;
	
	for(int iter = 0; iter < 11; iter++){
		
		int bucket = initialVals[iter] / 10;
		buckets[ bucket ].Insert( initialVals[iter] );
		
	}
	
	for(int iter = 0; iter < 10; iter++){
		
		std::cout << iter << ": " << buckets[ iter ] << std::endl;
		
	}
	
	std::cout << std::endl;

	return 0;

}
