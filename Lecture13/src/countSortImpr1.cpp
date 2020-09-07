/**********************************************
* File: countSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Counting Sort
**********************************************/
#include <string>
#include <iostream>

#include "../include/DynArr.h"
#include "../include/LinearProbe.h"

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){

	/* The Hash Table for the Counting Sort */
	HashTable<int, int> countSort;
	
	/* A vector of values to sort */
	DynArr<int> theVals;
	
	theVals.push_back( 7 ); 	theVals.push_back( 1 );
	theVals.push_back( 5 ); 	theVals.push_back( 7 );
	theVals.push_back( 1 ); 	theVals.push_back( 4 );
	theVals.push_back( 100 ); 	theVals.push_back( 44 );
	theVals.push_back( 9 );
	
	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;
	for(unsigned int iter = 0; iter < theVals.size(); iter++){
		
		if( countSort.contains( theVals[iter] )  ){
			
			// Increment the value
			countSort[ theVals[iter] ]++;
			
		}
		else{
			// Initialize the count at 1
			countSort.insert( {theVals[iter], 1} );
		}
		
		// Keep track of the largest value
		if(theVals[iter] > largestNum){
			largestNum = theVals[iter];
		}
		
	}
	
	// Print the updated Hash Table 
	std::cout << countSort << std::endl;

	return 0;
}
