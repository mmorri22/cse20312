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
* The class constructor defines the members out of order.
* This creates complexity similar to voidNodeBad2
*
* Running command "make classBad" will compile with warnings
*
* Running command "make classBadPQC" will use PQC rules.
* It will not compile, and force more complex errors.
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
			: theInt( intIn ), theDbl( dblIn ), theFloat( floatIn ) {}
			
			
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
	Node node2( -34.77, 44.96, 1842 );
	
	COUT << "Node 1 is at address " << &node1 << ENDL;
	node1.printNodeValues();
	COUT << ENDL;
	
	COUT << "Node 2 is at address " << &node2 << ENDL;
	node2.printNodeValues();
	
	return 0;
	
}