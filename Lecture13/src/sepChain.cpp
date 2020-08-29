/**********************************************
* File: sepChain.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of separate chaining
**********************************************/
#include <iterator>
#include <string>
#include <iostream>

#include "../include/DynArr.h"
#include "../include/LinearProbe.h"

const int numBuckets = 7;

/********************************************
* Function Name  : HashFunc
* Pre-conditions : int value
* Post-conditions: int
* 
* Hash Function: value % numBuckets 
********************************************/
int HashFunc(int value){
	return value % numBuckets;
}


/********************************************
* Function Name  : HashFunc
* Pre-conditions : std::string value
* Post-conditions: int
* 
* Hash Function returns size of string % numBuckets 
********************************************/
int HashFunc(std::string value){
	return (int)value.size() % numBuckets;
}


/********************************************
* Function Name  : insertVal
* Pre-conditions : HashTable<int, DynArr<T> >& sepChain, T value
* Post-conditions: none
* 
* Inserts the value into a Separate Chain Hash
********************************************/
template<class T>
void insertVal(HashTable<int, DynArr<T> >& sepChain, T value){
	
	// sepChain[ HashFunc(value) ] returns the vector with a call by reference
	sepChain[ HashFunc(value) ].push_back(value);
	
}


template<class T>
void printHash(HashTable<int, DynArr<T> >& sepChain){

	// Iterating through all buckets
	for(int i = 0; i < numBuckets; i++){
	
		std::cout << i << ": " << sepChain[i] << std::endl;

	}
	
}

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){

	HashTable<int, DynArr<int> > sepChain;
	
	/* Initialize List */
	for(int i = 0; i < numBuckets; i++){
		
		// Create a temporary 
		DynArr<int> temp;
		sepChain.insert( {i, temp} );
	}
	
	/* Insert 4, 13, 8, 10, 5, 15 */
	insertVal(sepChain, 4);		insertVal(sepChain, 13);
	insertVal(sepChain, 8);		insertVal(sepChain, 10);
	insertVal(sepChain, 5);		insertVal(sepChain, 15);

	/* Print the Hash */
	std::cout << sepChain << std::endl << std::endl;
	
	/* Print the Hash, only the buckets we need */
	printHash(sepChain);
	
	std::cout << char(10);

	HashTable<int, DynArr< std::string > > separStr;
	
	/* Initialize List */
	for(int i = 0; i < numBuckets; i++){
		DynArr< std::string > temp;
		separStr.insert( {i, temp} );
	}
	
	/* Insert words of length 4, 13, 8, 10, 5, 15 */
	insertVal(separStr, std::string("data"));
	insertVal(separStr, std::string("enlightenment"));
	insertVal(separStr, std::string("morrison"));
	insertVal(separStr, std::string("structures"));
	insertVal(separStr, std::string("pizza"));
	insertVal(separStr, std::string("rumpelstiltskin"));

	/* Print the Hash */
	std::cout << separStr << std::endl << std::endl;

	/* Print the Hash */
	printHash(separStr);

	return 0;
}
