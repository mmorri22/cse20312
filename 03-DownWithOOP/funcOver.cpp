/**********************************************
* File: funcOver.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates the benefits of cin in C++
* while providing improved tests with the string library
*
* Using Function Overloading
**********************************************/

#include <iostream> /*C++ version of stdio.h*/
#include <cstdlib> /* Equivalent of stdlib.h */
#include <string> /* String Library */


/********************************************
* Function Name  : PrintMe
* Pre-conditions : std::string s
* Post-conditions: none
* 
* Overloaded Function that prints a string  
********************************************/
void PrintMe (std::string s) {
   std::cout << "string s = \"" << s << "\"" << std::endl ;
}


/********************************************
* Function Name  : PrintMe
* Pre-conditions : int i
* Post-conditions: none
* 
* Overloaded Function the Prints an integer 
********************************************/
void PrintMe (int i) {
   std::cout << "int i = " << i << std::endl ;
}


/********************************************
* Function Name  : PrintMe
* Pre-conditions : std::string s, int i
* Post-conditions: none
* 
* Overloaded Function that prints a string and an integer 
********************************************/
void PrintMe (std::string s, int i) {
   std::cout << s << " " << i << std::endl ;
}


/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	std::string strX = "Hello, World";
	int tempX = 25;
	
	PrintMe(strX);
	PrintMe(tempX);
	PrintMe(strX, tempX);
		
	return 0;
}
