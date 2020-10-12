#ifndef BTREE1_H
#define BTREE1_H 

#include <cstdlib>
#include <iostream>
#include "BTreeNode3.h"

template< class T >
class BTree{
	
	private:
	
		unsigned int maxDegree;
		BTreeNode<T>* root;
		
		// Copy all the values in a node and it's subtree to the destination tree
		void copyTree( BTreeNode<T>*& destination, BTreeNode<T>* origin ){
			
			BTreeNode<T>* newNode = new BTreeNode<T>( origin->maxDegree );
			
			newNode->setAllChildNull();
			
			// Call the leftmost equal to the old 
			copy( newNode->childPtrs[0], origin->childPtrs[0] );
			
			// Iterate through the rest of the values and pointers 
			for( unsigned int iter = 0; iter < origin->count; iter++ ){
				
				newNode->values[iter] = origin->values[iter];
				
				copy( newNode->childPtrs[iter], origin->childPtrs[iter] );
			}
			
			newNode->count = origin->numVals;
			
			destination = newNode;
			
		}
		
		// Private Insert Method
		/* bool Insert( T newValue, BTreeNode<T>*& currNode ){
			
			if( !currNode->isLeaf ){
				
				unsigned int iter = 0;
				
				while( currNode->values[iter] < newValue && iter < currNode->count ){
					iter++;
				}
				
				// If returns true, we split and need to check
				if( Insert( newValue, currNode->childPtrs[ iter ] ) ){
					
					// If we are less than the current value, modify the value and insert into the node
					if( currNode->count < maxDegree - 1 ){
						
						currNode->values[ iter ] = currNode->childPtrs[ iter ]->values[ 0 ];
						
						currNode->childPtrs[ iter + 1 ] = currNode->childPtrs[ iter ]->childPtrs[ 1 ];
						
						currNode->childPtrs[ iter ] = currNode->childPtrs[ iter ]->childPtrs[ 0 ];
						
						currNode->count++;
						
						return false;
					}
					
					else{ 
						
						// Here is what we know 
						
						// currNode->count == maxDegree - 1
						// currNode->childPtrs[ iter ]->values[0] is the value that has been trickled up 
						// We have similar situation with splitNode 
						// We need to ensure pointers are maintained
						
						T trickleUpVal = currNode->childPtrs[ iter ]->values[0];

						COUT << "Hello A?" << ENDL;
						
						// BTreeNode<T> trickleUpPtr = *(currNode->childPtrs[ iter ]);
						
						COUT << "Hello 3?" << ENDL;
						
						BTreeNode< int >* newParent = new BTreeNode<int>( currNode->maxDegree );
						
						// Delete that pointer
						// delete currNode->childPtrs[ iter ];
				
						COUT << ENDL << "Testing the level split" << ENDL;
						COUT << "trickleUp:" << ENDL;
						printInOrderTraversal( 1, &trickleUpPtr );
						COUT << "currPtr:" << ENDL;
						printInOrderTraversal( 1, currNode );
						COUT  << ENDL << ENDL;
				
						newParent->splitChild( trickleUpVal, currNode );
						
						// Iterate through the new Parent's children 
						for( unsigned int jter = 0; jter < newParent->count; jter++ ){
							
							if( iter == jter ){
								
								newParent->childPtrs[jter] = currNode->childPtrs[ iter ];
							}
						}
						
						currNode = newParent;
						
						return true;
					}
					
				}
				
				return false;
				
			}
			
			else if( currNode->count == 0 ){
				
				currNode->values[0] = newValue;
				
				currNode->count++;	

				return false;
				
			}
			
			else if( currNode->count < maxDegree - 1 ){
				
				int iter = currNode->count;
				
				while( iter > 0 && currNode->values[iter - 1] > newValue ){
					
					currNode->childPtrs[iter+1] = currNode->childPtrs[iter];
					
					currNode->values[iter] = currNode->values[iter-1];
										
					iter--;
				}
				
				currNode->values[iter] = newValue;
				
				currNode->count++;
				
				return false;
				
			}
			
			else{
				
				BTreeNode< int >* newParent = new BTreeNode<int>( currNode->maxDegree );
				
				newParent->splitChild( newValue, currNode );
				
				currNode = newParent;
				
				currNode->isLeaf = false;
				
				return true;
				
			}
			
		} */
		
		
		void printInOrderTraversal( unsigned int level, BTreeNode<T>* currNode ){
			
			if( currNode == NULL ){
				return;
			}
			
			for( unsigned int iter = 0; iter < currNode->count; iter++ ){
				
				printInOrderTraversal( level+1, currNode->childPtrs[iter] );
				
				COUT << "Value: " << currNode->values[iter] << " at level " << level << ENDL;
				
			}
			
			printInOrderTraversal( level + 1, currNode->childPtrs[ currNode->count ] );
			
		}
		
	
	public:
	
		BTree( unsigned int maxDegreeIn ) : maxDegree( maxDegreeIn ), root( new BTreeNode<T>(maxDegree) ) {}
		
		~BTree(){ }
		
		BTree<T>& operator=( const BTree<T>& assign ){
			
			if( this != &assign ){
				
				if( this->root == NULL ){
					
					copy( this->root, assign->root );
					
				}
				
			}
			
			return *this;
		}
		
		// Search Methd
		BTreeNode<T>* search( T searchVal ){
			
			return (root == NULL) ? NULL : root->search( searchVal );
			
		}
		
		void Insert( T insertVal ){
			
			COUT << "Hello 1" << ENDL;
			
			// First, check if the root is NULL 
			if( root->count == 0 ){
				
				//root = new BTreeNode<T>( maxDegree );
				root->values[0] = insertVal;
				root->count = 1;
			}
			else{
				
				// If the root is full, then the tree grows in height 
				if( root->count == maxDegree - 1 ){
					
					COUT << "Hello 2" << ENDL;
					
					BTreeNode<T>* s = new BTreeNode<T>( maxDegree );
					
					s->childPtrs[0] = root;
				
					COUT << "Hello!" << ENDL;
					s->splitChild( 0, root );
					
					printInOrderTraversal(1, s);
					COUT << ENDL;
					
					unsigned int i = 0;
					if( s->values[0] < insertVal ){
						i++;
					}
					
					s->childPtrs[i]->insertNonFull( insertVal );
					
					root = s;
				}
				else{
					
					root->insertNonFull( insertVal );
				}
			}
			
			// Insert( value, root );
			
		}
		
		
		void printInOrderTraversal(){
			
			unsigned int level = 1;
			
			printInOrderTraversal(level, root);
			
			COUT << ENDL;
			
		}
		
		
};

#endif