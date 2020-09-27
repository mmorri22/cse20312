#ifndef MINHEAP_H
#define MINHEAP_H

#include "DynArr.h"
#include "MaxHeap.h"
#include <iostream>

template< class T >
class MinHeap : public MaxHeap<T>{
	
	private:
	
		// Move an inserted element as high as it can go
		void trickleUp( unsigned int heapLoc ){
			
			if( heapLoc == 0 )
				return;
			
			// could be implemented recursively
			unsigned int parent = (heapLoc - 1)/2;
			
			// Perform the trickle up 
			while( parent >= 0 && this->heapArray[ parent ] > this->heapArray[ heapLoc ] ){
				
				// Swap the elements
				T temp = this->heapArray[ parent ];
				this->heapArray[ parent ] = this->heapArray[ heapLoc ];
				this->heapArray[ heapLoc ] = temp;
				
				// Update the items if parent != 0
				if( parent != 0 ){
					heapLoc = parent;
					parent = (heapLoc - 1)/2;	// Dividing by 2 give O( lg(n) ) run time!
				}

			}
		}
		
		// Recursively trickle the element down 
		void trickleDown( unsigned int prevVal, unsigned int nextVal ){
			
			if( nextVal == 0 || nextVal >= this->heapArray.length() ){
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
			if( this->heapArray[nextVal] < this->heapArray[prevVal] ){
				
				T temp = this->heapArray[nextVal];
				this->heapArray[nextVal] = this->heapArray[prevVal];
				this->heapArray[prevVal] = temp;
				
			}
			
			// Check left for improper issues 
			if( this->heapArray[prevVal] > this->heapArray[2 * prevVal + 1] ){
				
				trickleDown( prevVal, 2 * prevVal + 1 );
				
				trickleDown( 2 * prevVal + 1, 4 * prevVal + 3 );
				trickleDown( 2 * prevVal + 1, 4 * prevVal + 4 );
				
			}
			
			// Check right for improper issues 
			else if( 2 * prevVal + 2 < this->heapArray.length() ){
				
				if( this->heapArray[prevVal] > this->heapArray[2 * prevVal + 2] ){
					
					trickleDown( prevVal, 2 * prevVal + 2 );
					
					trickleDown( 2 * prevVal + 2, 4 * prevVal + 5 );
					trickleDown( 2 * prevVal + 2, 4 * prevVal + 6 );
				}
				
			}
			
		}

		
	public:
	
		// Default Constructor
		MinHeap() : MaxHeap<T>() {}
		
		// Destructor
		~MinHeap() {}
	
		// Overloaded friend operator<<
		friend std::ostream& operator<<( std::ostream& output, const MinHeap<T>& theHeap ){
			
			for(unsigned int iter = 0; iter < theHeap.heapArray.length(); iter++ ){
				
				output << theHeap.heapArray[ iter ] << " ";
			}
			
			return output;
		}
};

#endif