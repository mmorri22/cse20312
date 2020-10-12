/**********************************************
* File: BTree.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
* The main header file which constructs a B-Tree 
* as presented in Notre Dame CSE 20312 Data Structures
**********************************************/
#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"

template<class T>
class BTree 
{ 

	private:
	
		BTreeNode<T> *root; // Pointer to root node 
		int t;  			// Degree 
		
		// Private Method
		void printInOrder( BTreeNode<T>* currPtr, std::ostream& out, unsigned int level ){
			
			if( currPtr == NULL ){
				
				return;
			}
			
			for( unsigned int iter = 0; iter < currPtr->numKeys; iter++ ){
				
				printInOrder( currPtr->childPtrs[iter], out, level + 1 );
				
				out << "{" << currPtr->keys[iter] << ", " << level << "}, ";
				
			}
			
			printInOrder( currPtr->childPtrs[ currPtr->numKeys ], out, level + 1 );
		}
	
	public:  
		/********************************************
		* Function Name  : t
		* Pre-conditions : degreeIn
		* Post-conditions: BTree<T>
		*  
		* Constructor (Initializes tree as empty) 
		********************************************/
		BTree<T>(int degreeIn) : root( NULL ), t(degreeIn) { }
		
		// The main function that inserts a new key in this B-Tree 
		void insert(T key) 
		{ 
			// If tree is empty 
			if (root == NULL) 
			{ 
				// Allocate memory for root 
				root = new BTreeNode<T>(t, true); 
				root->keys[0] = key;  // Insert key 
				root->numKeys = 1;  // Update number of keys in root 
			} 
			else // If tree is not empty 
			{ 
				// If root is full, then tree grows in height 
				if (root->numKeys == 2*t-1) 
				{ 
					// Allocate memory for new root 
					BTreeNode<T> *s = new BTreeNode<T>(t, false); 
		  
					// Make old root as child of new root 
					s->childPtrs[0] = root; 
		  
					// Split the old root and move 1 key to the new root 
					s->splitChild(0, root); 
		  
					// New root has two children now.  Decide which of the 
					// two children is going to have new key 
					int i = 0; 
					if (s->keys[0] < key) 
						i++; 
					s->childPtrs[i]->insertNonFull(key); 
		  
					// Change root 
					root = s; 
				} 
				else  // If root is not full, call insertNonFull for root 
					root->insertNonFull(key); 
			} 
		} 
		
		
		// Print an in-order traversal
		void printInOrder( std::ostream& out ){
			
			if( root == NULL ){
				
				out << "Empty Tree" << ENDL;
				return;
			}
			
			else{
				
				printInOrder( root, out, 1 );
				out << ENDL;
			}
		}
		
		
		/********************************************
		* Function Name  : traverse
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* function to traverse the tree 
		********************************************/
		void traverse(){  
			if (root != NULL) 
				root->traverse(); 
		} 
		
		
		void printFoundNodes(T key){  
		
			if (root == NULL)
				std::cout << "Tree is empty" << std::endl;
			
			else{
				std::cout << "Seeking " << key << ": ";
				root->printFoundNodes(key); 
			}
			
		} 

}; 

#endif
