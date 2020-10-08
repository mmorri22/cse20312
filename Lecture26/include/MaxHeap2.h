#ifndef MAXHEAP2_H
#define MAXHEAP2_H

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
		
		// Recursively trickle the element down 
		void trickleDown( unsigned int prevVal, unsigned int nextVal ){
			
			if( nextVal == 0 ){
				return;
			}
			
			// Determine the next value 
			unsigned int tempVal;
			if( prevVal % 2 == 1 ){
				tempVal = prevVal / 2 ;
			}
			else{
				tempVal = (prevVal / 2) - 1 ;
			}
			
			// Recursively call trickle down
			trickleDown( tempVal, prevVal );
			
			// If nextVal < prevVal, swap the elements
			if( heapArray[nextVal] > heapArray[prevVal] ){
				
				T temp = heapArray[nextVal];
				heapArray[nextVal] = heapArray[prevVal];
				heapArray[prevVal] = temp;
				
			}
			
		}


		
	
		DynArr<T> heapArray;	// Dynamic Array to Maintain the Heap
		
	public:
	
		// Default Constructor
		MaxHeap() : heapArray() {}
		
		// Destructor
		~MaxHeap() {}
		
		// Copy Constructor
		MaxHeap( const MaxHeap<T>& copy ) : heapArray( copy.size() ) {
			
			for( unsigned int iter = 0; iter < copy.heapArray.size(); iter++ ){
				// We want the elements in the same order
				heapArray.push_back( copy.heapArray[iter] );
			}
		}
		
		// Assignment Operator
		MaxHeap& operator=( const MaxHeap<T>& rhs ){
			
			if( this != &rhs ){
				for( unsigned int iter = 0; iter < rhs.heapArray.size(); iter++ ){
					
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
			trickleUp( heapArray.size() - 1 );
			
		}
		
		// Return the element at the to
		T top(){
			
			return heapArray[0];
			
		}
		
		bool empty(){
			
			return heapArray.size() == 0;
			
		}
		
		// Remove the top element 
		void pop(){
			
			// Ensure we cannot pop from empty array
			if( heapArray.size() == 0 ){
				std::cout << "Cannot pop from empty array\n";
				return;
			}
			
			// Swap the first and last element 
			heapArray[ 0 ] = heapArray[ heapArray.size() - 1 ];
			heapArray.erase( heapArray.size() - 1 );
			
			// Only trickle up if the length is greater than 1
			if ( heapArray.size() > 1 ){
			
				trickleDown( heapArray.size() / 2 - 1, heapArray.size() - 1 );

			}

			
		}
	
		// Overloaded friend operator<<
		friend std::ostream& operator<<( std::ostream& output, const MaxHeap<T>& theHeap ){
			
			for(unsigned int iter = 0; iter < theHeap.heapArray.size(); iter++ ){
				
				output << theHeap.heapArray[ iter ] << " ";
			}
			
			return output;
		}
};

#endif