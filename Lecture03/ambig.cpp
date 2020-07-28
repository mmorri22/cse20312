/**********************************************
* File: ambig.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates an example of ambiguous 
* overloading, where you cannot tell what the 
* output will be. Contains deliberate compiler errors
**********************************************/

#include <iostream> /*C++ version of stdio.h*/

/********************************************
* Function Name  : PrintMe
* Pre-conditions : std::string s
* Post-conditions: none
* 
* Overloaded Function that prints a string  
********************************************/
void PrintInt (int i) {
   i = i + 2;
   std::cout << i << std::endl;
}


/********************************************
* Function Name  : PrintMe
* Pre-conditions : const int i
* Post-conditions: none
* 
* Overloaded Function the Prints an integer 
********************************************/
void PrintInt (const int i) {

   i = i + 2;
   std::cout << i << std::endl;
   
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	int tempX = 25;

	PrintInt(tempX);

	std::cout << tempX << std::endl;
		
	return 0;
}
