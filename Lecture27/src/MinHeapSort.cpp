#include "../include/MinHeap.h" 
#include "../include/stack.h"

#include <iostream>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void popAndSort( MinHeap<T>& theHeap, stack<T>& result ){
	
	// Put the Max Element in the top of the stack
	result.push( theHeap.top() );
	
	// Push the element
	theHeap.pop( );
	
}

template< class T >
void pushAndPrint( MaxHeap<T>& theHeap, T theElem ){
	
	// Push the element
	theHeap.push( theElem );
	
	// Print the result
	COUT << "Pushing " << theElem << ": " << theHeap << ENDL;
	
}

int main() {
	
	// Create a MaxHeap with a Default Constructor
	MinHeap< int > heap1;
	DynArr< int > sorted1;
	
	// Push and Print 9 elements 
	COUT << "Testing heap1..." << ENDL;
	pushAndPrint( heap1, 33 );
	pushAndPrint( heap1, 21 );
	pushAndPrint( heap1, 81 );
	pushAndPrint( heap1, 27 );
	pushAndPrint( heap1, 1 );
	pushAndPrint( heap1, 7 );
	pushAndPrint( heap1, 44 );
	pushAndPrint( heap1, 0 );	
	pushAndPrint( heap1, 99 );	
	
	// Pop all 9 elements
	COUT << "Sorted Result 1: ";
	while( !heap1.empty() ){
		
		sorted1.push_back( heap1.top() );
		
		heap1.pop();
		
	}
	COUT << sorted1 << ENDL << ENDL;
	
	// Create a Max Heap with an overloaded Constructor
	COUT << "\nTesting heap2..." << ENDL;
	MinHeap< char > heap2;
	DynArr< char > sorted2;
	
	pushAndPrint( heap2, 'A' );
	pushAndPrint( heap2, 'B' );
	pushAndPrint( heap2, 'C' );
	pushAndPrint( heap2, 'Z' );
	pushAndPrint( heap2, 'Y' );
	pushAndPrint( heap2, 'X' );
	pushAndPrint( heap2, 'M' );	
	
	// Pop all 7 elements
	COUT << "Sorted Result 2: ";
	while( !heap2.empty() ){
		
		sorted2.push_back( heap2.top() );
		
		heap2.pop();
		
	}
	COUT << sorted2 << ENDL << ENDL;
	
	return 0;
	
}