#ifndef BTREE3_H
#define BTREE3_H 

#include <cstdlib>
#include <iostream>
#include "BTreeNode2.h"

#define COUT std::cout
#define ENDL std::endl

template< class T >
class BTree{
	
	private:
	
		unsigned int maxDegree;
		BTreeNode<T> *root;
		
		// Splits the node, and currPtr->values[0] will contain the 
		// median value of all the values and the element
		void splitNode( BTreeNode<T>*& currPtr, const T& element ){
			
			std::cout << "Help!" << std::endl;
						
			// Create the split left node, split right node, and node to rise up
			BTreeNode<T>* left = new BTreeNode<T>( currPtr->maxDegree );
			BTreeNode<T>* right = new BTreeNode<T>( currPtr->maxDegree );
			BTreeNode<T>* riseUp = new BTreeNode<T>( currPtr->maxDegree );
			
			// Make left and right the children of riseUp 
			riseUp->childPtrs[0] = left;
			riseUp->childPtrs[1] = right;
			
			// If the currPtr is a leaf, then left and right will be leaves 
			if( currPtr->isLeaf ){
				left->isLeaf = true;
				right->isLeaf = true;
			}
			
			// Otherwise, they will not be leaves 
			else{
				left->isLeaf = false;
				right->isLeaf = false;					
			}
			
			// The node to be risen is not a leaf
			riseUp->isLeaf = false;
			
			// Put in the left elements 
			unsigned int origIter = 0;
			unsigned int destIter = 0;
			
			// Fill in the left node
			while( destIter < currPtr->minDegree ){
				
				if( element > currPtr->values[ origIter ] || origIter != destIter ){
		
					left->values[destIter] = currPtr->values[ origIter ];
					left->childPtrs[destIter++] = currPtr->childPtrs[ origIter++ ];
					
				}
				
				else if( element <= currPtr->values[ origIter ] && origIter == destIter ){
					left->values[destIter++] = element;
				}
				
				left->count++;
			}
			
			// Determine the middle element 
			if( origIter == destIter && currPtr->values[ origIter ] <= element ){
				
				riseUp->values[0] = currPtr->values[ origIter++ ];
			}
			else if( origIter < destIter ){
				
				riseUp->values[0] = currPtr->values[ origIter++ ];
			}
			else{
				
				riseUp->values[0] = element;
			}
			
			riseUp->count++;

			
			// Fill in the right node
			// One of two cases
			// Case 1 - We already inserted the element, which means origIter == destIter
			if( origIter == destIter ){
			
				// We only want to insert the remainder
				destIter = 0;
				while( origIter < currPtr->maxDegree - 1 ){
					
					right->values[destIter] = currPtr->values[ origIter ];	
					right->childPtrs[destIter++] = currPtr->childPtrs[ origIter++ ];						
					right->count++;
				}
				
			}
			
			// Case 2 - We have not inserted the element
			else{
				destIter = 0;
				bool found = false;
				while( origIter < currPtr->maxDegree - 1 ){	

					if( currPtr->values[ origIter ] < element || found ){
						
						right->values[destIter] = currPtr->values[ origIter ];	
						right->childPtrs[destIter++] = currPtr->childPtrs[ origIter++ ];						
					}
					else if( currPtr->values[ origIter ] >= element && !found ){
						
						right->values[destIter++] = element;
						found = true;
					}
					
					right->count++;	
				}
				
				// If destIter is not equal to min degree, then the element is the last value
				
				if( !found ){
					right->values[destIter] = element;					
					right->count++;	
				}
			}
			
			// Set the currPtr called by reference equal to riseUp
			currPtr = riseUp;			
			
		}
		
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
			
			// Step 3 - If full, we must split the nodes 
			else{
				
				// Split the Node 
				splitNode( currPtr, element );
				
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
			
			COUT << ENDL;
		}
};

#endif