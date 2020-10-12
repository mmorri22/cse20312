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
 
#include <iostream> 
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl
  
// A BTree node 
template<class T> 
class BTreeNode 
{ 

	public: 
		int order;					// Order of the tree.
		int degree;      			// Minimum degree (defines the range for number of keys) 
		bool leaf; 					// Is true when node is leaf. Otherwise false 
		int numKeys;     			// Current number of keys 
		T *keys;  					// An array of keys 
		BTreeNode<T> **childPtrs; 	// An array of child pointers 

		void checkMemory(){
			
			if (this == NULL) {
				std::cerr <<  "Out of Memory" << std::endl;
				exit (-1);
			} 	
		}

		/********************************************
		* Function Name  : BTreeNode<T>
		* Pre-conditions : int orderIn, bool isLeaf
		* Post-conditions: none
		* 
		* BTreeNode Constructor 
		********************************************/
		BTreeNode<T>(int orderIn, bool isLeaf) : 
			order(orderIn), degree( (order+1)/2 ), leaf(isLeaf), numKeys(0), 
			keys(new T[order - 1]), childPtrs(new BTreeNode<T>*[order]) { 
			
			checkMemory();
		  
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
				if (childPtrs[i+1]->numKeys == order-1) 
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
			BTreeNode<T> *z = new BTreeNode<T>(y->order, y->leaf); 
			z->numKeys = degree - 1; 
		  
			// Copy the last (t-1) keys of y to z 
			for (int j = 0; j < degree-1; j++) 
				z->keys[j] = y->keys[j+degree]; 
		  
			// Copy the last t children of y to z 
			if (y->leaf == false) 
			{ 
				for (int j = 0; j < degree; j++) 
					z->childPtrs[j] = y->childPtrs[j+degree]; 
			} 
		  
			// Reduce the number of keys in y 
			y->numKeys = degree - 1; 
		  
			// Since this node is going to have a new child, 
			// create space of new child 
			for (int j = numKeys; j >= i+1; j--) 
				childPtrs[j+1] = childPtrs[j]; 
		  
			// Link the new child to this node 
			childPtrs[i+1] = z; 
		  
			// A key of y will move to this node. Find location of 
			// new key and move all greater keys one space ahead 
			for (int j = numKeys-1; j >= i; j--) 
				keys[j+1] = keys[j]; 
		  
			// Copy the middle key of y to this node 
			keys[i] = y->keys[degree-1]; 
		  
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
		* Function Name  : getPred
		* Pre-conditions : int index
		* Post-conditions: T
		* 
		* A function to get predecessor of keys[index]
		********************************************/
		T getPred(int index) 
		{ 
			// Keep moving to the right most node until we reach a leaf 
			BTreeNode<T> *cur=childPtrs[index]; 
			while (!cur->leaf) 
				cur = cur->childPtrs[cur->numKeys]; 
		  
			// Return the last key of the leaf 
			return cur->keys[cur->numKeys-1]; 
		} 
		  
		/********************************************
		* Function Name  : getSucc
		* Pre-conditions : int index
		* Post-conditions: T
		*  
		* Get the successor to the current key 
		********************************************/
		T getSucc(int index) 
		{ 
		  
			// Keep moving the left most node starting from childPtrs[index+1] until we reach a leaf 
			BTreeNode<T> *cur = childPtrs[index+1]; 
			while (!cur->leaf) 
				cur = cur->childPtrs[0]; 
		  
			// Return the first key of the leaf 
			return cur->keys[0]; 
		} 


		  
		/********************************************
		* Function Name  : remove
		* Pre-conditions : T key
		* Post-conditions: none
		*  
		* A function to remove the key k from the sub-tree rooted with this node
		********************************************/
		void remove(T key) 
		{ 
			int index = findKey(key); 
		  
			// The key to be removed is present in this node 
			if (index < numKeys && keys[index] == key) 
			{ 
		  
				// If the node is a leaf node - removeFromLeaf is called 
				// Otherwise, removeFromNonLeaf function is called 
				if (leaf) 
					removeFromLeaf(index); 
				else
					removeFromNonLeaf(index); 
			} 
			else
			{ 
		  
				// If this node is a leaf node, then the key is not present in tree 
				if (leaf) 
				{ 
					std::cout << "The key "<< key <<" is does not exist in the tree\n"; 
					return; 
				} 
		  
				// The key to be removed is present in the sub-tree rooted with this node 
				// The flag indicates whether the key is present in the sub-tree rooted 
				// with the last child of this node 
				bool flag = ( (index==numKeys)? true : false ); 
		  
				// If the child where the key is supposed to exist has less that t keys, 
				// we fill that child 
				if (childPtrs[index]->numKeys < degree) 
					fill(index); 
		  
				// If the last child has been merged, it must have merged with the previous 
				// child and so we recurse on the (index-1)th child. Else, we recurse on the 
				// (index)th child which now has atleast t keys 
				if (flag && index > numKeys) 
					childPtrs[index-1]->remove(key); 
				else
					childPtrs[index]->remove(key); 
			} 
			return; 
		} 
		  
		/********************************************
		* Function Name  : removeFromLeaf
		* Pre-conditions : int index
		* Post-conditions: none
		* 
		* A function to remove the index-th key from this node - which is a leaf node 
		********************************************/
		void removeFromLeaf (int index) 
		{ 
		  
			// Move all the keys after the index-th pos one place backward 
			for (int i = index+1; i < numKeys; ++i) 
				keys[i-1] = keys[i]; 
		  
			// Reduce the count of keys 
			numKeys--; 
		  
			return; 
		} 
		  
		/********************************************
		* Function Name  : removeFromNonLeaf
		* Pre-conditions : int index
		* Post-conditions: none
		* 
		* A function to remove the index-th key from this node - which is a non-leaf node 		
		********************************************/
		void removeFromNonLeaf(int index) 
		{ 
		  
			T key = keys[index]; 
		  
			// If the child that precedes k (childPtrs[index]) has atleast t keys, 
			// find the predecessor 'pred' of k in the subtree rooted at 
			// childPtrs[index]. Replace k by pred. Recursively delete pred 
			// in childPtrs[index] 
			if (childPtrs[index]->numKeys >= degree) 
			{ 
				T pred = getPred(index); 
				keys[index] = pred; 
				childPtrs[index]->remove(pred); 
			} 
		  
			// If the child childPtrs[index] has less that t keys, examine childPtrs[index+1]. 
			// If childPtrs[index+1] has atleast t keys, find the successor 'succ' of k in 
			// the subtree rooted at childPtrs[index+1] 
			// Replace key by succ 
			// Recursively delete succ in childPtrs[index+1] 
			else if  (childPtrs[index+1]->numKeys >= degree) 
			{ 
				T succ = getSucc(index); 
				keys[index] = succ; 
				childPtrs[index+1]->remove(succ); 
			} 
		  
			// If both childPtrs[index] and childPtrs[index+1] has less that t keys,merge k and all of childPtrs[index+1] 
			// into childPtrs[index] 
			// Now childPtrs[index] contains 2t-1 keys 
			// Free childPtrs[index+1] and recursively delete k from childPtrs[index] 
			else
			{ 
				merge(index); 
				childPtrs[index]->remove(key); 
			} 
			return; 
		} 
		  		  
		/********************************************
		* Function Name  : fill
		* Pre-conditions : int index
		* Post-conditions: none
		*  
		* A function to fill child childPtrs[index] which has less than t-1 keys
		********************************************/
		void fill(int index) 
		{ 
		  
			// If the previous child(childPtrs[index-1]) has more than t-1 keys, borrow a key 
			// from that child 
			if (index!=0 && childPtrs[index-1]->numKeys>=degree) 
				borrowFromPrev(index); 
		  
			// If the next child(childPtrs[index+1]) has more than t-1 keys, borrow a key 
			// from that child 
			else if (index!=numKeys && childPtrs[index+1]->numKeys >= degree) 
				borrowFromNext(index); 
		  
			// Merge childPtrs[index] with its sibling 
			// If childPtrs[index] is the last child, merge it with with its previous sibling 
			// Otherwise merge it with its next sibling 
			else
			{ 
				if (index != numKeys) 
					merge(index); 
				else
					merge(index-1); 
			} 
			return; 
		} 
		  
		/********************************************
		* Function Name  : borrowFromPrev
		* Pre-conditions : int index
		* Post-conditions: none
		*  
		* A function to borrow a key from childPtrs[index-1] and insert it 
		* into childPtrs[index] 
		********************************************/
		void borrowFromPrev(int index) 
		{ 
		  
			BTreeNode *child=childPtrs[index]; 
			BTreeNode *sibling=childPtrs[index-1]; 
		  
			// The last key from childPtrs[index-1] goes up to the parent and key[index-1] 
			// from parent is inserted as the first key in childPtrs[index]. Thus, the  loses 
			// sibling one key and child gains one key 
		  
			// Moving all key in childPtrs[index] one step ahead 
			for (int i=child->numKeys-1; i>=0; --i) 
				child->keys[i+1] = child->keys[i]; 
		  
			// If childPtrs[index] is not a leaf, move all its child pointers one step ahead 
			if (!child->leaf) 
			{ 
				for(int i=child->numKeys; i>=0; --i) 
					child->childPtrs[i+1] = child->childPtrs[i]; 
			} 
		  
			// Setting child's first key equal to keys[index-1] from the current node 
			child->keys[0] = keys[index-1]; 
		  
			// Moving sibling's last child as childPtrs[index]'s first child 
			if(!child->leaf) 
				child->childPtrs[0] = sibling->childPtrs[sibling->numKeys]; 
		  
			// Moving the key from the sibling to the parent 
			// This reduces the number of keys in the sibling 
			keys[index-1] = sibling->keys[sibling->numKeys-1]; 
		  
			child->numKeys += 1; 
			sibling->numKeys -= 1; 
		  
			return; 
		} 
		  
		/********************************************
		* Function Name  : borrowFromNext
		* Pre-conditions : int index
		* Post-conditions: none
		* 
		* A function to borrow a key from the childPtrs[index+1] and place 
		* it in childPtrs[index]
		********************************************/
		void borrowFromNext(int index) 
		{ 
		  
			BTreeNode<T>* child = childPtrs[index]; 
			BTreeNode<T>* sibling = childPtrs[index+1]; 
		  
			// keys[index] is inserted as the last key in childPtrs[index] 
			child->keys[(child->numKeys)] = keys[index]; 
		  
			// Sibling's first child is inserted as the last child 
			// into childPtrs[index] 
			if (!(child->leaf)) 
				child->childPtrs[(child->numKeys)+1] = sibling->childPtrs[0]; 
		  
			//The first key from sibling is inserted into keys[index] 
			keys[index] = sibling->keys[0]; 
		  
			// Moving all keys in sibling one step behind 
			for (int i=1; i<sibling->numKeys; ++i) 
				sibling->keys[i-1] = sibling->keys[i]; 
		  
			// Moving the child pointers one step behind 
			if (!sibling->leaf) 
			{ 
				for(int i=1; i<=sibling->numKeys; ++i) 
					sibling->childPtrs[i-1] = sibling->childPtrs[i]; 
			} 
		  
			// Increasing and decreasing the key count of childPtrs[index] and childPtrs[index+1] 
			// respectively 
			child->numKeys += 1; 
			sibling->numKeys -= 1; 
		  
			return; 
		} 
		  
		/********************************************
		* Function Name  : merge
		* Pre-conditions : int index
		* Post-conditions: none
		* 
		* A function to merge childPtrs[index] with childPtrs[index+1] 
		* childPtrs[index+1] is freed after merging 
		********************************************/
		void merge(int index) 
		{ 
			BTreeNode<T> *child = childPtrs[index]; 
			BTreeNode<T> *sibling = childPtrs[index+1]; 
		  
			// Pulling a key from the current node and inserting it into (t-1)th 
			// position of childPtrs[index] 
			child->keys[degree-1] = keys[index]; 
		  
			// Copying the keys from childPtrs[index+1] to childPtrs[index] at the end 
			for (int i=0; i<sibling->numKeys; ++i) 
				child->keys[i+degree] = sibling->keys[i]; 
		  
			// Copying the child pointers from childPtrs[index+1] to childPtrs[index] 
			if (!child->leaf) 
			{ 
				for(int i=0; i<=sibling->numKeys; ++i) 
					child->childPtrs[i+degree] = sibling->childPtrs[i]; 
			} 
		  
			// Moving all keys after index in the current node one step before - 
			// to fill the gap created by moving keys[index] to childPtrs[index] 
			for (int i=index+1; i<numKeys; ++i) 
				keys[i-1] = keys[i]; 
		  
			// Moving the child pointers after (index+1) in the current node one 
			// step before 
			for (int i=index+2; i<=numKeys; ++i) 
				childPtrs[i-1] = childPtrs[i]; 
		  
			// Updating the key count of child and the current node 
			child->numKeys += sibling->numKeys+1; 
			numKeys--; 
		  
			// Freeing the memory occupied by sibling 
			delete(sibling); 
			return; 
		} 

}; 

#endif
