/**********************************************
* File: structNode.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Taking the code from voidFunc and putting it into
* a C++ struct. voidFunc is the same code, but at 
* a lower level of abstraction. This level is closer
* to object-oriented programming.
*
* Shows how the public nature of structs allows for 
* ease of modification of the struct members
*
* Lecture 02 - Part 2 - Slide 29
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

struct Node{
	
	double theDbl;
	float theFloat;
	int theInt;
	
	Node(double dblIn, float floatIn, int intIn ) 
		: theDbl( dblIn ), theFloat( floatIn ), theInt( intIn ) {}
		
		
	void printNodeValues(){
		
		COUT << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;
		
		COUT << "Double:  " << theDbl << "\t at address " << &theDbl << ENDL;
		COUT << "Float:  " << theFloat << "\t at address " << &theFloat << ENDL;
		COUT << "Integer:  " << theInt << "\t at address " << &theInt << ENDL;
		
	}
	
};

int main(void){
	
	Node node1( -0.625, (float)1.5625, 131 );
	
	node1.printNodeValues();
	
	node1.theDbl = -34.77;
	node1.theFloat = (float)44.96;
	node1.theInt = 1842;
	
	node1.printNodeValues();
	
	return 0;
	
}