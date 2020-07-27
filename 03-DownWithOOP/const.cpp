/**********************************************
* File: ptr.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of outputting  
* pointers in C++
**********************************************/

#include <iostream> /*C++ version of stdio.h*/

const double PI = 3.14159;

/********************************************
* Function Name  : CircleArea
* Pre-conditions : double radius 
* Post-conditions: double
* 
* Calculates the area of a circle 
********************************************/
double CircleArea( double radius ){
	
	return PI * radius * radius;
	
}

/********************************************
* Function Name  : CircleCircumference
* Pre-conditions : double radius 
* Post-conditions: double
* 
* Calculates the circumfrence of a circle 
********************************************/
double CircleCircumference ( const double radius ){
	
	return PI * radius;
	
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	const double radius = 5;
	
	std::cout << "The circle's radius is " << radius << std::endl;
	std::cout << "The value of Pi is " << PI << std::endl;
	
	std::cout << "The area of the circle is " 	
		<< CircleArea( radius ) << std::endl;
		
	std::cout << "The circumfrence of the circle is " 
		<< CircleCircumference( radius ) << std::endl;

	return 0;
}
