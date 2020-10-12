/**********************************************
* File: BTreeNode.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Implementation of a Templated C++ Class BTreeNode 
*
* Developed from the implementation from CLRS Text
* T. H. et al Cormen, Introduction to algorithms. Cambridge, MA: MIT Press, 2009.
**********************************************/
#ifndef BTREENODE_H
#define BTREENODE_H
 
#include<iostream>

#define COUT std::cout
#define ENDL std::endl
  
// A BTree node 
template<class T> 
class BTreeNode 
{ 

	public: 
		int t;      				// Minimum degree (defines the range for number of keys) 
		T *keys;  					// An array of keys 
		BTreeNode<T> **childPtrs; 	// An array of child pointers 
		int numKeys;     			// Current number of keys 
		bool leaf; 					// Is true when node is leaf. Otherwise false 

		/********************************************
		* Function Name  : BTreeNode<T>
		* Pre-conditions : int _t, bool _leaf
		* Post-conditions: none
		* 
		* BTreeNode Constructor 
		********************************************/
		// t is the minimum Degree
		// maximum number of keys is 2*t - 1
		// number of nodes is 2*t
		BTreeNode<T>(int t_In, bool leaf_In) : t(t_In), keys( new T[2*t-1] ), 
			childPtrs( new BTreeNode<T>* [2*t] ), numKeys(0), leaf(leaf_In) { 
		  
		} 
	   
	       
		/********************************************
		* Function Name  : search
		* Pre-conditions : T key
		* Post-conditions: BTreeNode<T>*
		* 
		* A function to search a key in the subtree rooted with this node. 
		********************************************/
		BTreeNode<T>* search(T key){ 
			// Find the first key greater than or equal to k 
			int i = 0; 
			while (i < numKeys && key > keys[i]) 
				i++; 
		  
			// If the found key is equal to k, return this node 
			if(i < numKeys){
				if (keys[i] == key) 
					return this; 
			}
		  
			// If the key is not found here and this is a leaf node 
			if (leaf == true) 
				return NULL; 
		  
			// Go to the appropriate child 
			return childPtrs[i]->search(key); 
		}  
		
		/********************************************
		* Function Name  : insertNonFull
		* Pre-conditions : T key
		* Post-conditions: none
		*
		* A utility function to insert a new key in this node 
		* The assumption is, the node must be non-full when this 
		* function is called 
		********************************************/
		void insertNonFull(T key) 
		{ 
			// Initialize index as index of rightmost element 
			int i = numKeys-1; 
		  
			// If this is a leaf node 
			if (leaf == true) 
			{ 
				// The following loop does two things 
				// a) Finds the location of new key to be inserted 
				// b) Moves all greater keys to one place ahead 
				while (i >= 0 && keys[i] > key) 
				{ 
					keys[i+1] = keys[i]; 
					i--; 
				} 
		  
				// Insert the new key at found location 
				keys[i+1] = key; 
				numKeys = numKeys+1; 
			} 
			else // If this node is not leaf 
			{ 
				// Find the child which is going to have the new key 
				while (i >= 0 && keys[i] > key) 
					i--; 
		  
				// See if the found child is full 
				if (childPtrs[i+1]->numKeys == 2*t-1) 
				{ 
					// If the child is full, then split it 
					splitChild(i+1, childPtrs[i+1]); 
		  
					// After split, the middle key of childPtrs[i] goes up and 
					// childPtrs[i] is splitted into two.  See which of the two 
					// is going to have the new key 
					if (keys[i+1] < key) 
						i++; 
				} 
				childPtrs[i+1]->insertNonFull(key); 
			} 
		} 
	  
		/********************************************
		* Function Name  : splitChild
		* Pre-conditions : int i, BTreeNode<T> *y
		* Post-conditions: none
		* 
		* A utility function to split the child y of this node 
		* Note that y must be full when this function is called 
		********************************************/
		void splitChild(int i, BTreeNode<T> *y) 
		{ 
			// Create a new node which is going to store (t-1) keys 
			// of y 
			BTreeNode<T>* rightChild = new BTreeNode<T>(y->t, y->leaf); 
			rightChild->numKeys = t - 1; 
		  
			// Copy the last (t-1) keys of y to rightChild 
			for (int j = 0; j < t-1; j++) 
				rightChild->keys[j] = y->keys[j+t]; 
		  
			// Copy the last t children of y to rightChild 
			if (y->leaf == false) 
			{ 
				for (int j = 0; j < t; j++) 
					rightChild->childPtrs[j] = y->childPtrs[j+t]; 
			} 
		  
			// Reduce the number of keys in y 
			y->numKeys = t - 1; 
		  
			// Since this node is going to have a new child, 
			// create space of new child 
			for (int j = numKeys; j >= i+1; j--) 
				childPtrs[j+1] = childPtrs[j]; 
		  
			// Link the new child to this node 
			childPtrs[i+1] = rightChild; 
		  
			// A key of y will move to this node. Find location of 
			// new key and move all greater keys one space ahead 
			for (int j = numKeys-1; j >= i; j--) 
				keys[j+1] = keys[j]; 
		  
			// Copy the middle key of y to this node 
			keys[i] = y->keys[t-1]; 
		  
			// Increment count of keys in this node 
			numKeys = numKeys + 1; 
		} 
		

		/********************************************
		* Function Name  : findKey
		* Pre-conditions : T key
		* Post-conditions: int
		*  
		* A utility function that returns the index of the first key that is 
		* greater than or equal to k
		********************************************/
		int findKey(T key) 
		{ 
			int index=0; 
			while (index < numKeys && keys[index] < key) 
				++index; 
			return index; 
		} 


		/********************************************
		* Function Name  : traverse
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* A function to traverse all nodes in a subtree rooted with this node 
		********************************************/
		void traverse()
		{ 
			// There are numKeys keys and numKeys+1 children, travers through numKeys keys 
			// and first numKeys children 
			int i; 
			for (i = 0; i < numKeys; i++) 
			{ 
				// If this is not leaf, then before printing key[i], 
				// traverse the subtree rooted with child childPtrs[i]. 
				if (leaf == false) 
					childPtrs[i]->traverse(); 
				std::cout << " " << keys[i]; 
			} 
		  
			// Print the subtree rooted with last child 
			if (leaf == false) 
				childPtrs[i]->traverse(); 
		} 
		
		
		void printFoundNodes(T key){ 
			// Find the first key greater than or equal to k 
			int i = 0; 
			while (i < numKeys && key > keys[i]){ 
				std::cout << keys[i] << " ";
				i++; 
			}
		  
			// If the found key is equal to k, return this node 
			if(i < numKeys){
				if (keys[i] == key){ 
					std::cout << keys[i] << "... key found!" << std::endl;
					return; 
					
				}
			}
		  
			// If the key is not found here and this is a leaf node 
			if (leaf == true) {
				std::cout << "... node not found!" << std::endl;
				return; 
			}
		  
			// Go to the appropriate child 
			childPtrs[i]->printFoundNodes(key); 
		}  
}; 

#endif
