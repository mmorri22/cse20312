#ifndef MAXHEAP1_H
#define MAXHEAP1_H

#include "DynArr.h"
#include <iostream>

template< class T >
class MaxHeap{
	
	private:
	
		// Move an inserted element as high as it can go
		void trickleUp( unsigned int heapLoc ){
			
			if( heapLoc == 0 )
				return;
			
			// could be implemented recursively
			unsigned int parent = (heapLoc - 1)/2;
			
			// Perform the trickle up 
			// Parent >= 0 ensures we do not exceed the array bound 
			// We also should stop once the trickle up condition is met
			while( parent >= 0 && heapArray[ parent ] < heapArray[ heapLoc ] ){
				
				// Swap the elements
				T temp = heapArray[ parent ];
				heapArray[ parent ] = heapArray[ heapLoc ];
				heapArray[ heapLoc ] = temp;
				
				// Update the items if parent != 0
				if( parent != 0 ){
					heapLoc = parent;
					parent = (heapLoc - 1)/2;	// Dividing by 2 give O( lg(n) ) run time!
				}

			}
		}
	
		DynArr<T> heapArray;	// Dynamic Array to Maintain the Heap
		
	public:
	
		// Default Constructor
		MaxHeap() : heapArray() {}
		
		// Destructor
		~MaxHeap() {}
		
		// Copy Constructor
		MaxHeap( const MaxHeap<T>& copy ) : heapArray( copy.length() ) {
			
			for( unsigned int iter = 0; iter < copy.heapArray.length(); iter++ ){
				// We want the elements in the same order
				heapArray.push_back( copy.heapArray[iter] );
			}
		}
		
		// Assignment Operator
		MaxHeap& operator=( const MaxHeap<T>& rhs ){
			
			if( this != &rhs ){
				for( unsigned int iter = 0; iter < rhs.heapArray.length(); iter++ ){
					
					this->heapArray.push_back( rhs.heapArray[iter] );
				}				
			}
			return *this;
		}
		
		// Push elements onto the Heap 
		void push( const T& element ){
			
			// Push the element to the back of the array
			heapArray.push_back( element );
			
			// Promote the Element we just pushed back
			trickleUp( heapArray.length() - 1 );
			
		}
	
		// Overloaded friend operator<<
		friend std::ostream& operator<<( std::ostream& output, const MaxHeap<T>& theHeap ){
			
			for(unsigned int iter = 0; iter < theHeap.heapArray.length(); iter++ ){
				
				output << theHeap.heapArray[ iter ] << " ";
			}
			
			return output;
		}
};

#endif