/**********************************************
* File: countSort1.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Counting Sort
**********************************************/
#include <string>
#include <iostream>

#include "../include/DynArr.h"
#include "../include/LinearProbe.h"

int main(){
	
	/* A vector of values to sort */
	DynArr<int> theVals;
	
	theVals.push_back( 7 ); 	theVals.push_back( 1 );
	theVals.push_back( 5 ); 	theVals.push_back( 7 );
	theVals.push_back( 1 ); 	theVals.push_back( 4 );
	theVals.push_back( 100 ); 	theVals.push_back( 44 );
	theVals.push_back( 9 );
	
	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;
	for(unsigned int iter = 0; iter < theVals.length(); iter++){
		
		if(theVals[iter] > largestNum){
			largestNum = theVals[iter];
		}
	}
	
	/* Print the largest number */
	std::cout << "Maximum Value: " << largestNum << std::endl;

	return 0;
}
