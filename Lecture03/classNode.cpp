/**********************************************
* File: classNode.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Taking the code from voidFunc and putting it into
* a C++ struct. voidFunc is the same code, but at 
* a lower level of abstraction. This code has data hiding
* and object oriented programming
*
* Lecture 03 - Slide 22
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
	Node node2( -34.77, (float)44.96, 1842 );
	
	COUT << "Node 1 is at address " << &node1 << ENDL;
	
	node1.printNodeValues();
	COUT << ENDL;
	
	COUT << "Node 2 is at address " << &node2 << ENDL;
	node2.printNodeValues();
	
	return 0;
	
}