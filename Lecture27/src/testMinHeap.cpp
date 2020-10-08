#include "../include/MinHeap.h" 
#include "../include/stack.h"

#include <iostream>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void popAndPrint( MinHeap<T>& theHeap ){
	
	// Get the Top Element
	T top = theHeap.top( );
	
	// Push the element
	theHeap.pop( );
	
	// Print the result
	COUT << "Popping " << top << ": " << theHeap << ENDL;
	
}

template< class T >
void pushAndPrint( MaxHeap<T>& theHeap, T theElem ){
	
	// Push the element
	theHeap.push( theElem );
	
	// Print the result
	COUT << "Pushing " << theElem << ": " << theHeap << ENDL;
	
}

int main() {
	
	// Create a MinHeap with a Default Constructor
	MinHeap< int > heap1;
	
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
	while( !heap1.empty() ){
		
		popAndPrint( heap1 );
		
	}
	
	// Create a MinHeap with a Default Constructor
	MinHeap< char > heap2;
	
	// Create a Min Heap of characters
	COUT << ENDL << "Testing heap2..." << ENDL;	
	pushAndPrint( heap2, 'D' );
	pushAndPrint( heap2, 'F' );
	pushAndPrint( heap2, 'A' );
	pushAndPrint( heap2, 'E' );
	pushAndPrint( heap2, 'Q' );
	pushAndPrint( heap2, 'R' );
	pushAndPrint( heap2, 'M' );
	
	// Pop all 9 elements
	while( !heap2.empty() ){
		
		popAndPrint( heap2 );
		
	}
	
	return 0;
	
}