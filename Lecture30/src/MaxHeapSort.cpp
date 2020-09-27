#include "../classes/MaxHeap3.h" 
#include "../classes/stack.h"

#include <iostream>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void popAndSort( MaxHeap<T>& theHeap, stack<T>& result ){
	
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
	MaxHeap< int > heap1;
	stack<int> stack1;
	
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
		
		popAndSort( heap1, stack1 );
		
	}
	
	COUT << "Sorted Result 1: ";
	while( !stack1.empty() ){
		
		COUT << stack1.top() << " ";
		
		stack1.pop();
		
	}
	COUT << ENDL << ENDL;
	
	// Create a Max Heap with an overloaded Constructor
	COUT << "\nTesting heap2..." << ENDL;
	MaxHeap< char > heap2;
	stack< char > stack2;
	
	pushAndPrint( heap2, 'A' );
	pushAndPrint( heap2, 'B' );
	pushAndPrint( heap2, 'C' );
	pushAndPrint( heap2, 'Z' );
	pushAndPrint( heap2, 'Y' );
	pushAndPrint( heap2, 'X' );
	pushAndPrint( heap2, 'M' );	
	
	// Pop all 9 elements
	while( !heap2.empty() ){
		
		popAndSort( heap2, stack2 );
		
	}
	
	COUT << "Sorted Result 2: ";
	while( !stack2.empty() ){
		
		COUT << stack2.top() << " ";
		
		stack2.pop();
		
	}
	COUT << ENDL << ENDL;
	
	return 0;
	
}