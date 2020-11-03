/**********************************************
* File: QuadraticTestProbing.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/
#include <iostream>
#include "../include/QuadraticProbing.h"
using namespace std;

/********************************************
* Function Name  : main
* Pre-conditions :  
* Post-conditions: int
*  
********************************************/
int main( )
{
    HashTable<int> h1(7);
	
	// 76, 40, 48, and 5
	h1.insert(76);
	h1.insert(40);
	h1.insert(48);
	h1.insert(5);
	h1.insert(55);
	
	h1.printHash(std::cout);

    return 0;
}
