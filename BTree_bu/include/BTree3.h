#ifndef BTREE3_H
#define BTREE3_H 

#include <cstdlib>
#include <iostream>
#include "BTreeNode2.h"

template< class T >
class BTree{
	
	private:
	
		unsigned int maxDegree;
		BTreeNode<T> *root;
		
		void insert( BTreeNode<T>*& currPtr, const T& element ){
			
			// Step 1 - Allocate a BTreeNode if the node is empty
			if( currPtr == NULL ){
				
				// Allocate the node
				currPtr = new BTreeNode<T>( maxDegree );
				
				// Set the node as a leaf 
				currPtr->isLeaf = true;
				
				// Set the first value to the element
				currPtr->values[0] = element;	
				
				// Increment the count
				currPtr->count++;
				
				return;
			}
			
			// Step 2 - If the node is not empty, but is not full, insert in order 
			if( currPtr->count < maxDegree - 1){
				
				// First, find the location
				unsigned int iter = 0;
				while( element > currPtr->values[iter] && iter < currPtr->count ){
					iter++;
				}
				
				// Every value after iter should move to the right to the right 
				for(unsigned int jter = currPtr->count; jter > iter; jter--){
					currPtr->values[ jter ] = currPtr->values[ jter - 1 ];
				}
				
				// Set the iter value equal to element 
				currPtr->values[ iter ] = element;
				
				// Increment the count
				currPtr->count++;
			
			}
			
		}
		
		// Traverse the Tree
		void traversal(BTreeNode<T>* printNode, unsigned int level) {

			if (printNode != NULL) {
				
				unsigned int iter;
				
				for (iter = 0; iter < printNode->count; iter++) {
					
					traversal(printNode->childPtrs[iter], level + 1);
					
					std::cout<< "{Level " << level << ", " << printNode->values[iter] << "} ";
					
				}
				
				// Traverse the last pointer
				traversal(printNode->childPtrs[iter], level + 1);
			}
		}
		
	
	public:
	
		BTree( unsigned int maxDegreeIn ) : maxDegree( maxDegreeIn ), root( NULL ) {}
		
		void insert( const T& element ){

			insert( root, element );
			
		}
		
		void traversal(){
			
			traversal( root, 1 );
		}
};

#endif