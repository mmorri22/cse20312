/**********************************************
* File: intPtr.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains pointer basic to help the student
* become more familiar with C pointers, including
* pointer addresses, data, adereferencing, and void pointers 
*
* Lecture 2 - Slides 9-12
**********************************************/

#include <iostream>

/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(void){
	
	int a = 1;
	
	/* Pointer declaration */
	int *firstPtr;
	
	/* Set the pointer to the register address of a */
	firstPtr = &a;
	
	std::cout << "The info on firstPtr " << (char)10;
	std::cout << "firstPtr register address:\t" << (void *)&firstPtr << "\n";
	std::cout << "firstPtr value is:\t\t" <<  (void *)firstPtr << std::endl;
	std::cout << "Address of a is:\t\t" << &a << std::endl;
	std::cout << "value pointed to by firstPtr:\t" << *firstPtr << std::endl;
	std::cout << "value of a:\t\t\t" << a << std::endl;

	return 0;
}

