#include "../include/MinHeap.h"
#include "../include/DoubleHash.h"
#include "../include/Priority.h"
#include "../include/stack.h" 

#include <iostream>
#include <cstdlib>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void printKMostFreq( MinHeap< Priority<T> >& heap ){
	
	unsigned int iter = 1;
	
	stack< Priority<T> > theStack;
	
	while( !heap.empty() ){
		
		theStack.push( heap.top() );
		heap.pop();
	}
	
	while( !theStack.empty() ){
		
			COUT << "The " << iter << "-th most frequent is " << theStack.top() << ENDL;
			
			theStack.pop();
			
			iter++;
	}
}


template< class T >
void heapifyHistogram( DoubleHash<T, int>& countSortHash, MinHeap< Priority<T> >& heap, unsigned int mostFreq ){

	unsigned int numPushed = 0;

	for(unsigned int i = 0; i <= countSortHash.getNumBuckets(); i++){
		
		try{
			Priority<T> tempPriority( countSortHash.getKey(i), countSortHash.getValue(i) );
			
			// If we get here, then the exception was not thrown
			if( numPushed < mostFreq ){
				
				heap.push( tempPriority );
				numPushed++;
			}
			else{
				
				// if the element is greater than the top
				if( tempPriority > heap.top() ){
					
					heap.pop();	// Removing the top removes the smallest
					heap.push( tempPriority );	// Push the new element
				}
			}
		}
		catch( const std::exception& theException ){
			// Do nothing other than catch
		}
	}
}

template< class T >
void getHistogram( DoubleHash<T, int>& countSortHash, DynArr<T>& theVals ){
	
	/* Iterate through each of the values in the Dynamic Array */
	for(unsigned int iter = 0; iter < theVals.size(); iter++){
		
		if( countSortHash.contains( theVals[iter] )  ){
			
			// Increment the value
			countSortHash[ theVals[iter] ]++;
			
		}
		else{
			// Initialize the count at 1
			countSortHash.insert( {theVals[iter], 1} );
		}
	}

	std::cout << countSortHash << std::endl << std::endl;
}

int main(){

	/* The Hash Table for the Counting Sort */
	DoubleHash<int, int> countSortHash;
	
	/* A vector of values to sort */
	DynArr<int> theVals;
	
	/* Push the elements onto the Dynamic Array */
	theVals.push_back( 9 );		theVals.push_back( 9 );		theVals.push_back( 7 ); 	theVals.push_back( 1 );
	theVals.push_back( 5 ); 	theVals.push_back( 7 );		theVals.push_back( 1 ); 	theVals.push_back( 4 );
	theVals.push_back( 100 ); 	theVals.push_back( 44 );	theVals.push_back( 9 );		theVals.push_back( 100 );
	theVals.push_back( 100 );	theVals.push_back( 9 );		theVals.push_back( 9 );		theVals.push_back( 7 );	
	theVals.push_back( 100 );
	
	/* Get the Histogram */
	getHistogram(countSortHash, theVals);
	
	/* Create the Minimum Heap and mostFreq */
	MinHeap< Priority<int> > heap;
	unsigned int mostFreq = 4;
	
	/* Get the mostFreq number of elements */
	heapifyHistogram( countSortHash, heap, mostFreq );
	
	/* Print the results */
	printKMostFreq( heap );

	return 0;
}
