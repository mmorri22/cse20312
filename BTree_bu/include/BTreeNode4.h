#ifndef BTREENODE3_H
#define BTREENODE3_H

#include <cstdlib>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

template< class T>
struct BTreeNode {
	
	// Members
	unsigned int maxDegree;		// The maximum degree of the BTree
	T* values;					// The data itself
	BTreeNode<T> **childPtrs;	// Pointers to the children
	bool isLeaf;				// Indicates if the node is a leaf
	unsigned int count;			// Current number of values
	unsigned int minDegree;		// Minimum Degree

	// Constructor
	BTreeNode( unsigned int maxDegreeIn ) : 
	
		// Set the maximum degree with the input
		maxDegree( maxDegreeIn ), 
		
		// Create the array for the values of max degree - 1
		values( new T[maxDegree - 1] ), 
		
		// Create pointers for the maximum degree
		childPtrs( new BTreeNode<T>* [maxDegree] ),
		
		// Indicate the node is a leaf, and the count is 0
		isLeaf(true), count( 0 ), 
		
		// Set the minimum degree of the tree
		minDegree( (maxDegree % 2 == 1 ) ? maxDegree/2 : maxDegree/2 - 1 ){
			
			// Set all the children of the node initially to NULL
			setAllChildNull();
			
		}
	
	// Destructor
	~BTreeNode(){ 
	
		/* 
	
		// Max Degree is the number of pointers, so iterate through them
		// and delete the child pointers
		for (unsigned int iter = 0; iter < maxDegree; iter++) {
			
			if( childPtrs[iter] != NULL ){
				delete childPtrs[iter];
			}
		}		
		
		*/
	
	}
	
	// Copy Constructor
	BTreeNode( const BTreeNode<T>& copy ) : maxDegree( copy.maxDegree ), values( new T[maxDegree - 1] ), 
		childPtrs( new BTreeNode<T>*[maxDegree] ), isLeaf( copy.isLeaf ), count( copy.count ),
		minDegree( copy.minDegree ){
		
		for( unsigned int iter = 0; iter < count; iter++ ){
			
			values[iter] = copy.values[iter];
			
		}
		
		// Initialize all the children to NULL
		setAllChildNull();
	}
	
	// Assignment Operator
	BTreeNode<T>& operator=( const BTreeNode<T>& rhs ){
		
		if( this != &rhs ){
			
			this->maxDegree = rhs.maxDegree; // Set the maxDegree to the rhs
			
			this->values = new T[ this->maxDegree - 1 ]; // Create the array for values
		
			this->childPtrs = new BTreeNode<T>*[ this->maxDegree ]; // Create new child Pointers
			
			this->isLeaf = rhs.isLeaf; // Set the boolean for if the node is a leaf
			
			this->count = rhs.count; // Set the current number of elements in the array
			
			// Copy the values in the rhs array
			for( unsigned int iter = 0; iter < this->count; iter++ ){
				
				this->values[iter] = rhs.values[iter];
			}
			
			this->setAllChildNull(); // Initialize all the children to NULL
		}
		
		return *this;
	}
	

	// Assignment Operator
	BTreeNode<T>* operator=( const BTreeNode<T>* rhs ){
		
		this = (void *)&rhs;

		return *this;
	}
	
	// Set all the child pointers to NULL 
	void setAllChildNull(){
		
		// Max Degree is the number of pointers, so iterate through them
		// and make each child initially NULL
		for (unsigned int iter = 0; iter < maxDegree; iter++) {
			
			childPtrs[iter] = NULL;
		}
	}
	
	// Returns the index of the first value that is 
	// greater than or equal to theValue
	unsigned int findValue(T theValue)
	{
		unsigned int index=0;
		
		// Iterate until we exceed the count of find location
		while (index < count && values[index] < theValue){
			++index;
		}
		
		return index;
	}
	
	
	// Indicates if the node is full
	bool isFull(){
		
		return count == maxDegree - 1;
		
	}
	
	
	// A utility function to split the child y of this node
	// Note that y must be full when this function is called
	void splitChild(T& newValue, BTreeNode<T>*& y)
	{
		// Create a new node which is going to store (t-1) keys of y
		BTreeNode<T>* left = new BTreeNode(y->maxDegree);
		BTreeNode<T>* right = new BTreeNode(y->maxDegree);
		
		// If the node to be split is a leaf, then z will be a leaf
		left->isLeaf = y->isLeaf;
		right->isLeaf = y->isLeaf;
		
		// This node is now no longer a leaf 
		isLeaf = false;
		
		// Get location
		unsigned int valueLocation = y->findValue( newValue );
		
		// There are now three cases
		// Case 1 - valueLocation is less than minDegree
		if( valueLocation < minDegree ){
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			while( y->values[iter] < newValue ){
				
				left->values[ left->count ] = y->values[iter];
				
				iter++;	left->count++;
			}
			
			// Now we have found the location for the new Value 
			left->values[iter] = newValue;
			left->count++;
			
			// Get the rest of the left
			for( ; iter < minDegree - 1; iter++ ){
				
				left->values[ left->count ] = y->values[iter];
				
				left->count++;				
				
			}
			
			// Make the current node's first value as the middle 
			values[0] = y->values[iter];
			iter++;		count++;
			
			// Put the rest in the new right child 
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				
				right->count++;				
				
			}
		}
		
		// Case 2 - valueLocation is equal to the minDegree 
		else if( valueLocation == minDegree ){
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			// Get the left values
			for( ; iter < minDegree; iter++ ){
				
				left->values[ left->count ] = y->values[iter];
				
				left->count++;				
			}
			
			// Make the current node's first value as the newValue 
			values[0] = newValue;
			count++;
			
			// Put the rest in the new right child 
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				
				right->count++;				
			}			
			
		}
		
		// Case 3 - valueLocation is greater than the minDegree 
		else{
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			// Get the left values
			for( ; iter < minDegree; iter++ ){
				
				left->values[iter] = y->values[iter];
				
				left->count++;				
			}

			// The middle value is the value at min degree
			// Make the current node's first value as the middle 
			values[0] = y->values[iter];
			iter++;	count++;

			COUT << iter << " " << y->values[iter] << ENDL;
			while( iter < maxDegree - 1 && y->values[iter] < newValue ){
				
				right->values[ right->count ] = y->values[iter];
				iter++;	right->count++;
			}	

			// Now we have found the location for the new Value
			COUT << iter - minDegree - 1 << " " << newValue << ENDL;			
			right->values[iter - minDegree - 1] = newValue;
			right->count++;
			
			// Get the rest of the left
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				
				right->count++;				
				
			}		
			
		}
		
		// Set the parent's node 0 to left, and 1 to right
		childPtrs[0] = left;
		childPtrs[1] = right;
	}
};


#endif