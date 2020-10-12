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
		int order;			// Order
		int degree;  		// Degree 
		
		
		void copy( BTreeNode<T>*& destination, BTreeNode<T>*& origin ){
			
			// Set the newNode equal to the old 
			BTreeNode<T>* newNode = new BTreeNode<T>(order, origin->leaf);

			// Call the leftmost 
			copy(newNode->childPtrs[0], origin->childPtrs[0]);

			// Iterate through the rest of the values and pointers
			for(unsigned int iter = 0; iter < order-1; iter++){
				
				newNode->values[iter] = origin->values[iter];

				copy(newNode->childPtrs[iter+1], origin->childPtrs[iter+1]);
			}
			
			newNode->numVals = origin->numVals;

			destination = newNode;
			
		}
		
		
		void deleteTree( BTreeNode<T>*& theNode ){

				// Step 1: Check if the node is NULL	
			if(theNode == NULL)
				return;

			// Step 2: Iterate through all
			for(unsigned int iter = 0; iter < order; iter++){
				
				deleteTree( theNode->childPtrs[iter] );  // Step 2a
				delete theNode->childPtrs[iter];         // Step 2b
				
			}

			//delete theNode;
		}
		
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

	// Constructor
    BTree<T>(int orderIn) : root(NULL), order(orderIn), degree( (order+1)/2 ) { }
	
	~BTree(){
		deleteTree(root);
	}
	
	BTree(const BTree<T>& copyTree){
		
		copy( this->root, copyTree->root );
		
	}

	BTree<T>& operator=(const BTree<T>& assign){
			
		if(this != &assign){
			if(this->root == NULL)
				return *this;

			copy( this->root, assign->root );
		}

		return *this;
	}

  
    // Traverse
    void traverse(){  
		if (root != NULL) 
			root->traverse(); 
	} 
  
    // Search
    BTreeNode<T>* search(T key){  
		return (root == NULL)? NULL : root->search(key); 
	} 
	
	
    void printFoundNodes(T key){  
		if (root == NULL)
			std::cout << "Tree is empty" << std::endl;
		
		else{
			std::cout << "Seeking " << key << ": ";
			root->printFoundNodes(key); 
		}
	} 
	
	// Insert
	void insert(T key) 
	{ 
		// If tree is empty 
		if (root == NULL) 
		{ 
			// Allocate memory for root 
			root = new BTreeNode<T>(order, true); 
			root->keys[0] = key;  // Insert key 
			root->numKeys = 1;  // Update number of keys in root 
		} 
		else // If tree is not empty 
		{ 
			// If root is full, then tree grows in height 
			if (root->numKeys == order-1) 
			{ 
				// Allocate memory for new root 
				BTreeNode<T> *s = new BTreeNode<T>(order, false); 
	  
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
	
	// Remove
	void remove(T key) 
	{ 
		if (root == NULL) 
		{ 
			std::cout << "The tree is empty\n"; 
			return; 
		} 
	  
		// Call the remove function for root 
		root->remove(key); 
	  
		// If the root node has 0 keys, make its first child as the new root 
		//  if it has a child, otherwise set root as NULL 
		if (root->numKeys==0) 
		{ 
			BTreeNode<T> *tmp = root; 
			if (root->leaf) 
				root = NULL; 
			else
				root = root->childPtrs[0]; 
	  
			// Free the old root 
			delete tmp; 
		} 
		return; 
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

}; 

#endif
