#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
#include <cstdlib> 	// NULL keyword

#define COUT std::cout
#define ENDL std::endl

// A BTree node
template< class T >
struct BTreeNode
{

    unsigned int max;   // Maximum B-Tree Degree
    bool leaf; 			// Is true when node is leaf. Otherwise false
    T *keys;  			// Array containing the data keys
    BTreeNode<T> **C; 	// Array of child pointers
	unsigned int min;	// Minimum Degree
    int n;     			// Current number of keys

	// Default Constructor
    BTreeNode(int maxIn, bool leafIn): max(maxIn), leaf(leafIn), keys( new T[max-1] ), C( new BTreeNode<T> *[max] ), 
		min( max / 2 ), n( 0 ) { }
	
	// Copy Constructor
    BTreeNode( const BTreeNode<T>& copy ): max(copy.max), leaf(copy.leaf), keys( new T[max-1] ), C( new BTreeNode<T>*[max] ), 
		min(  copy.min ), n( copy.n ) { 
	
		for( unsigned int iter = 0; iter < n; iter++ ){
			
			this->keys[iter] = copy.keys[iter];
		}
	}
	
	~BTreeNode() {
		delete C;
	}
	
	BTreeNode<T>& operator=( const BTreeNode<T>& rhs ){
		
		if( this != &rhs ){
			
			this->max = rhs.max;
			this->leaf = rhs.leaf;
			
			this->keys = new T[max-1];
			this->C = new BTreeNode<T>*[max];
			this->min = rhs.min;
			this->n = rhs.n;
		
			for( unsigned int iter = 0; iter < n; iter++ ){
				
				this->keys[iter] = rhs.keys[iter];
				
			}
		}
		
		return *this;
	}
	
	BTreeNode<T>* operator=( const BTreeNode<T>* rhs ){
		
		std::cout << "Operator?" << std::endl;
		
		this = rhs;
		
		return *this;
	}

	// A utility function that returns the index of the first key that is
	// greater than or equal to k
	int findKey(T k)
	{
		int index=0;
		while (index<n && keys[index] < k){
			++index;
		}
		return index;
	}

	// A function to remove the key k from the sub-tree rooted with this node
	void remove(T k)
	{
		int index = findKey(k);

		// The key to be removed is present in this node
		if (index < n && keys[index] == k)
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
				COUT << "The key "<< k <<" is does not exist in the tree" << ENDL;
				return;
			}

			// The key to be removed is present in the sub-tree rooted with this node
			// The flag indicates whether the key is present in the sub-tree rooted
			// with the last child of this node
			bool flag = ( (index==n)? true : false );

			// If the child where the key is supposed to exist has less that t keys,
			// we fill that child
			if (C[index]->n < min )
				fill(index);

			// If the last child has been merged, it must have merged with the previous
			// child and so we recurse on the (index-1)th child. Else, we recurse on the
			// (index)th child which now has atleast t keys
			if (flag && index > n)
				C[index-1]->remove(k);
			else
				C[index]->remove(k);
		}
		return;
	}

	// A function to remove the index-th key from this node - which is a leaf node
	void removeFromLeaf (int index)
	{

		// Move all the keys after the index-th pos one place backward
		for (int i=index+1; i<n; ++i)
			keys[i-1] = keys[i];

		// Reduce the count of keys
		n--;

		return;
	}

	// A function to remove the index-th key from this node - which is a non-leaf node
	void removeFromNonLeaf(int index)
	{

		T k = keys[index];

		// If the child that precedes k (C[index]) has atleast t keys,
		// find the predecessor 'pred' of k in the subtree rooted at
		// C[index]. Replace k by pred. Recursively delete pred
		// in C[index]
		if (C[index]->n >= min)
		{
			T pred = getPred(index);
			keys[index] = pred;
			C[index]->remove(pred);
		}

		// If the child C[index] has less that t keys, examine C[index+1].
		// If C[index+1] has atleast t keys, find the successor 'succ' of k in
		// the subtree rooted at C[index+1]
		// Replace k by succ
		// Recursively delete succ in C[index+1]
		else if  (C[index+1]->n >= min)
		{
			T succ = getSucc(index);
			keys[index] = succ;
			C[index+1]->remove(succ);
		}

		// If both C[index] and C[index+1] has less that t keys,merge k and all of C[index+1]
		// into C[index]
		// Now C[index] contains 2t-1 keys
		// Free C[index+1] and recursively delete k from C[index]
		else
		{
			merge(index);
			C[index]->remove(k);
		}
		return;
	}

	// A function to get predecessor of keys[index]
	T getPred(int index)
	{
		// Keep moving to the right most node until we reach a leaf
		BTreeNode<T> *cur=C[index];
		while (!cur->leaf)
			cur = cur->C[cur->n];

		// Return the last key of the leaf
		return cur->keys[cur->n-1];
	}

	// Get the successor
	T getSucc(int index)
	{

		// Keep moving the left most node starting from C[index+1] until we reach a leaf
		BTreeNode<T> *cur = C[index+1];
		while (!cur->leaf)
			cur = cur->C[0];

		// Return the first key of the leaf
		return cur->keys[0];
	}

	// A function to fill child C[index] which has less than t-1 keys
	void fill(int index)
	{

		// If the previous child(C[index-1]) has more than t-1 keys, borrow a key
		// from that child
		if (index!=0 && C[index-1]->n >= min)
			borrowFromPrev(index);

		// If the next child(C[index+1]) has more than t-1 keys, borrow a key
		// from that child
		else if (index!=n && C[index+1]->n >= min)
			borrowFromNext(index);

		// Merge C[index] with its sibling
		// If C[index] is the last child, merge it with with its previous sibling
		// Otherwise merge it with its next sibling
		else
		{
			if (index != n)
				merge(index);
			else
				merge(index-1);
		}
		return;
	}

	// A function to borrow a key from C[index-1] and insert it
	// into C[index]
	void borrowFromPrev(int index)
	{

		BTreeNode<T> *child=C[index];
		BTreeNode<T> *sibling=C[index-1];

		// The last key from C[index-1] goes up to the parent and key[index-1]
		// from parent is inserted as the first key in C[index]. Thus, the  loses
		// sibling one key and child gains one key

		// Moving all key in C[index] one step ahead
		for (int i=child->n-1; i>=0; --i)
			child->keys[i+1] = child->keys[i];

		// If C[index] is not a leaf, move all its child pointers one step ahead
		if (!child->leaf)
		{
			for(int i=child->n; i>=0; --i)
				child->C[i+1] = child->C[i];
		}

		// Setting child's first key equal to keys[index-1] from the current node
		child->keys[0] = keys[index-1];

		// Moving sibling's last child as C[index]'s first child
		if (!leaf)
			child->C[0] = sibling->C[sibling->n];

		// Moving the key from the sibling to the parent
		// This reduces the number of keys in the sibling
		keys[index-1] = sibling->keys[sibling->n-1];

		child->n += 1;
		sibling->n -= 1;

		return;
	}

	// A function to borrow a key from the C[index+1] and place
	// it in C[index]
	void borrowFromNext(int index)
	{

		BTreeNode<T> *child=C[index];
		BTreeNode<T> *sibling=C[index+1];

		// keys[index] is inserted as the last key in C[index]
		child->keys[(child->n)] = keys[index];

		// Sibling's first child is inserted as the last child
		// into C[index]
		if (!(child->leaf))
			child->C[(child->n)+1] = sibling->C[0];

		//The first key from sibling is inserted into keys[index]
		keys[index] = sibling->keys[0];

		// Moving all keys in sibling one step behind
		for (int i=1; i<sibling->n; ++i)
			sibling->keys[i-1] = sibling->keys[i];

		// Moving the child pointers one step behind
		if (!sibling->leaf)
		{
			for(int i=1; i<=sibling->n; ++i)
				sibling->C[i-1] = sibling->C[i];
		}

		// Increasing and decreasing the key count of C[index] and C[index+1]
		// respectively
		child->n += 1;
		sibling->n -= 1;

		return;
	}

	// A function to merge C[index] with C[index+1]
	// C[index+1] is freed after merging
	void merge(int index)
	{
		BTreeNode<T> *child = C[index];
		BTreeNode<T> *sibling = C[index+1];

		// Pulling a key from the current node and inserting it into (t-1)th
		// position of C[index]
		child->keys[ min - 1 ] = keys[index];

		// Copying the keys from C[index+1] to C[index] at the end
		for (int i=0; i<sibling->n; ++i)
			child->keys[i + min] = sibling->keys[i];

		// Copying the child pointers from C[index+1] to C[index]
		if (!child->leaf)
		{
			for(int i=0; i<=sibling->n; ++i)
				child->C[i+min] = sibling->C[i];
		}

		// Moving all keys after index in the current node one step before -
		// to fill the gap created by moving keys[index] to C[index]
		for (int i=index+1; i<n; ++i)
			keys[i-1] = keys[i];

		// Moving the child pointers after (index+1) in the current node one
		// step before
		for (int i=index+2; i<=n; ++i)
			C[i-1] = C[i];

		// Updating the key count of child and the current node
		child->n += sibling->n+1;
		n--;

		// Freeing the memory occupied by sibling
		delete(sibling);
		return;
	}

	// A utility function to insert a new key in this node
	// The assumption is, the node must be non-full when this
	// function is called
	void insertNonFull(T k)
	{
		// Initialize index as index of rightmost element
		int i = n-1;

		// If this is a leaf node
		if (leaf == true)
		{
			// The following loop does two things
			// a) Finds the location of new key to be inserted
			// b) Moves all greater keys to one place ahead
			while (i >= 0 && keys[i] > k)
			{
				keys[i+1] = keys[i];
				i--;
			}

			// Insert the new key at found location
			keys[i+1] = k;
			n = n+1;
		}
		else // If this node is not leaf
		{
			// Find the child which is going to have the new key
			while (i >= 0 && keys[i] > k)
				i--;

			// See if the found child is full
			if (C[i+1]->n == max - 1)
			{
				// If the child is full, then split it
				splitChild(i+1, C[i+1]);

				// After split, the middle key of C[i] goes up and
				// C[i] is splitted into two.  See which of the two
				// is going to have the new key
				if (keys[i+1] < k)
					i++;
			}
			C[i+1]->insertNonFull(k);
		}
	}

	// A utility function to split the child y of this node
	// Note that y must be full when this function is called
	void splitChild(unsigned int i, BTreeNode<T> *y)
	{
		// Create a new node which is going to store (t-1) keys
		// of y
		BTreeNode<T> *z = new BTreeNode(y->max, y->leaf);
		z->n = min - 1;

		// Copy the last (t-1) keys of y to z
		for (int j = 0; j < min-1; j++){
			z->keys[j] = y->keys[j+min];
		}

		// Copy the last t children of y to z
		if (y->leaf == false)
		{
			for (int j = 0; j < min; j++)
				z->C[j] = y->C[j+min];
		}

		// Reduce the number of keys in y
		y->n = min - 1;

		// Since this node is going to have a new child,
		// create space of new child
		for (int j = n; j >= i+1; j--)
			C[j+1] = C[j];

		// Link the new child to this node
		C[i+1] = z;

		// A key of y will move to this node. Find location of
		// new key and move all greater keys one space ahead
		for (int j = n-1; j >= i; j--)
			keys[j+1] = keys[j];

		// Copy the middle key of y to this node
		keys[i] = y->keys[min-1];

		// Increment count of keys in this node
		n = n + 1;
	}

	// Function to traverse all nodes in a subtree rooted with this node
	void traverse( std::ostream& output, unsigned int level )
	{
		// There are n keys and n+1 children, travers through n keys
		// and first n children
		int i;
		
		for (i = 0; i < n; i++)
		{
			// If this is not leaf, then before printing key[i],
			// traverse the subtree rooted with child C[i].
			if (leaf == false){
				
				C[i]->traverse( output, level + 1 );
			}
			output << "{ L" << level << ", " << keys[i] << "} ";
		}

		// Print the subtree rooted with last child
		if (leaf == false)
			C[i]->traverse( output, level + 1 );
	}

	// Function to search key k in subtree rooted with this node
	BTreeNode<T>* search(T k)
	{
		// Find the first key greater than or equal to k
		int i = 0;
		while (i < n && k > keys[i])
			i++;

		// If the found key is equal to k, return this node
		if (keys[i] == k)
			return this;

		// If key is not found here and this is a leaf node
		if (leaf == true)
			return NULL;

		// Go to the appropriate child
		return C[i]->search(k);
	}

};


#endif