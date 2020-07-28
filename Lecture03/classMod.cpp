/**********************************************
* File: structNode.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Taking the code from voidFunc and putting it into
* a C++ struct. voidFunc is the same code, but at 
* a lower level of abstraction. This code has data hiding
* and object oriented programming
*
* Shows an example of a get/set function
*
* Lecture 02 - Part 2 - Slide 29
**********************************************/

#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

class Node{
	
	private:
	
		double theDbl;
		float theFloat;
		int theInt;
	
	public:
	
		Node(double dblIn, float floatIn, int intIn ) 
			: theDbl( dblIn ), theFloat( floatIn ), theInt( intIn ) {}
		
		
		void setDbl( double dblIn ){
			
			theDbl = dblIn;
			
		}
		
		int getInt(){
			
			return theInt;
			
		}
			
		void printNodeValues(){
			
			COUT << "-----------------------------" << ENDL;
			COUT << "Initial address of 'this': " << this << ENDL << ENDL;
			
			COUT << "Double:  " << theDbl << "\t at address " << &theDbl << ENDL;
			COUT << "Float:  " << theFloat << "\t at address " << &theFloat << ENDL;
			COUT << "Integer:  " << theInt << "\t at address " << &theInt << ENDL;
			
		}
	
};

int main(void){
	
	Node node1( -0.625, 1.5625, 131 );
	
	node1.printNodeValues();
	
	node1.setDbl(-34.77);
	
	node1.printNodeValues();
	
	COUT << ENDL << "Get Example: " << node1.getInt() << ENDL;
	
	return 0;
	
}