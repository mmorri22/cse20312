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
			
			COUT << "HELLO HELLO HELLO!?! 2" << ENDL;
			
		// Initialize all the children to NULL
		setAllChildNull();
		
		for( unsigned int iter = 0; iter < count; iter++ ){
			
			values[iter] = copy.values[iter];
			*(childPtrs[iter]) = *(copy.childPtrs[iter]);
			
		}
		
		// Only do this if copy.count > 0, otherwise Segmentation fault
		if( copy.count > 0 ){
			*(childPtrs[ copy.count ]) = *(copy.childPtrs[ copy.count ]);
		}		
	
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
			this->setAllChildNull();
			for( unsigned int iter = 0; iter < this->count; iter++ ){
				
				this->values[iter] = rhs.values[iter];
				*(this->childPtrs[iter]) = *(rhs.childPtrs[iter]);
			}
			
			if( rhs.count > 0 ){
				*(this->childPtrs[ rhs.count ]) = *(rhs.childPtrs[ rhs.count ]);
			}
		}
		
		return *this;
	}
	

	// Assignment Operator
	BTreeNode<T>* operator=( const BTreeNode<T>* rhs ){
		
		COUT << "Bad hello?" << ENDL;
		
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
	
	// Search and return a node pointing to that value or NULL 
	BTreeNode<T>* search( T searchVal ){
		
		unsigned int iter = 0;
		
		while( iter < count && searchVal > values[iter] ){
			iter++;
		}
		
		if( iter < count ){
			
			if( values[iter] == searchVal ){
				return this;
			}
		}
		
		if( isLeaf ){
			return NULL;
		}
		
		return childPtrs[iter]->search( searchVal );
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
	
	// Get the Predecessor
	T getPred( unsigned int index ){
		
		BTreeNode<T>* currPtr = childPtrs[index];
		
		while( !currPtr->isLeaf ){
			
			currPtr = currPtr->childPtrs[ currPtr->count ];
		}
		
		return currPtr->values[ currPtr->count - 1 ];
		
	}
	
	
	// Get the successor 
	T getSucc( unsigned int index ){
		
		BTreeNode<T>* currPtr = childPtrs[index + 1];
		
		while( !currPtr->isLeaf ){
			
			currPtr = currPtr->childPtrs[ 0 ];
		}
		
		return currPtr->values[ 0 ];
				
	}
	
	
	void splitChild(unsigned int i, BTreeNode<T>*& y )
	{
		
		// Create a node which will store the right keys in the split
		BTreeNode<T>* rightNode = new BTreeNode<T>( maxDegree );
		
		// Copy all the elements to the right to the right node 
		// For odd length node - minDegree + 1 on the right 
		// Even length will have minDegree on both left and right 
		unsigned int start = 0;
		unsigned int length = ( maxDegree ) / 2 - 1;
		if( ( maxDegree - 1 ) % 2 == 1 ){
			
			start = minDegree;
			
		}
		else{
			
			start = minDegree + 1;
		}
		
		// Set the number of keys for the right node
		rightNode->count = ( maxDegree ) / 2 - 1;
		
		COUT << "rightNode->count " << rightNode->count << ENDL;
		
		// Copy the last elements from start to the rightNode 
		for( unsigned int j = 0; j < length; j++ ){
			
			rightNode->values[j] = y->values[ start + j ];
			
		}
		
		// Copy the last length children of y to rightChild
		if( !y->isLeaf ){
			
			for( unsigned int j = 0; j < length + 1; j++ ){
				
				rightNode->childPtrs[j] = y->childPtrs[ start + j ];
			}
		}
		
		// Reduce the number of keys in y 
		// We added length keys 
		y->count -= length;
		
		// Since THIS node is going to have a new child, create space for it 
		if( count > 0 ){
			
			for( unsigned int j = count; j >= i+1; j-- ){
				
				childPtrs[j+1] = childPtrs[j];
			}
		}
		
		// Now, we make the new right child to this node - i+1 
		childPtrs[i+1] = rightNode;
		
		// A value of y will move to this node. We need to find the location 
		// of the new value and move all greater value one space ahead	
		if( count > 0 ){
			for( int j = count - 1; j >= i; j-- ){
				
				COUT << "Values Check: " << values[j] << ENDL;
				
				values[j+1] = values[j];
			}
		}
		
		// Copy the middle value of y to this node 
		values[i] = y->values[ length ];
		
		// Increment the count of THIS node
		count++;
	}
	
	
	void insertNonFull( T insertVal ){
		
		// Initialize index as index of rightmost element 
		unsigned int i = count - 1;
		
		// If this is a leaf node 
		if( isLeaf ){
			
			// The following loop does two things
			// a) Finds the location of new key to be inserted 
			// b) Moves all greater keys to one place ahead 
			while( i >= 0 && values[i] > insertVal ){
				values[ i + 1 ] = values [ i ];
				i--;
			}
			
			// Insert the new value at the correct location 
			values[i+1] = insertVal;
			count++;
			
		}
		else{	// If this node is not a leaf 
			
			// Find where the child is going to have the new key 
			while( i >= 0 && values[i] > insertVal ){
				i--;
			}
			
			// Determine if the found child is full 
			if( childPtrs[i+1]->isFull() ){
				
				// Since the child is full, we will split it 
				splitChild( i+1, childPtrs[i+1] );
				
				// After the splie, the middle child will go up 
				// childPtrs[i] is split in half. Now we determine which ig 
				// going to have the new key 
				if( values[ i+1 ] < insertVal ){
					i++;
				}
				
			}
			
			COUT << "PRINT AFTER SPLIT " << ENDL;
			for( unsigned int iter = 0; iter < count; iter++ ){
				
				COUT << values[iter] << " ";
			}
			
			COUT << ENDL;
			
			// Now insert into i+1
			childPtrs[i+1]->insertNonFull( insertVal );
			
		}
		
	}
	
	// A utility function to split the child y of this node
	// Note that y must be full when this function is called
/*	void splitChild(T& newValue, BTreeNode<T>*& y)
	{
		// Create a new node which is going to store (t-1) keys of y
		BTreeNode<T>* left = new BTreeNode(y->maxDegree);
		BTreeNode<T>* right = new BTreeNode(y->maxDegree);
		
		// If the node to be split is a leaf, then z will be a leaf
		left->isLeaf = true;
		right->isLeaf = true;
		
		// Get location
		unsigned int valueLocation = y->findValue( newValue );
		
		// There are now three cases
		// Case 1 - valueLocation is less than minDegree
		if( valueLocation < minDegree ){
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			while( y->values[iter] < newValue ){
				
				left->values[ left->count ] = y->values[iter];
				left->childPtrs[ left->count ] = y->childPtrs[iter];
				
				iter++;	left->count++;
			}
			
			// Now we have found the location for the new Value 
			left->values[iter] = newValue;
			left->childPtrs[ iter ] = y->childPtrs[iter];
			left->count++;
			
			// Get the rest of the left
			for( ; iter < minDegree - 1; iter++ ){
				
				left->values[ left->count ] = y->values[iter];
				left->childPtrs[ left->count ] = y->childPtrs[iter];
				left->count++;				
				
			}
			
			// Set the right most pointer in left B-Tree node to NULL
			left->childPtrs[ iter ] = NULL;
			
			// Make the current node's first value as the middle 
			values[0] = y->values[iter];
			iter++;		count++;
			
			// Put the rest in the new right child 
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				left->childPtrs[ right->count ] = y->childPtrs[iter];
				right->count++;				
				
			}
			
			// Set the right-most Node to NULL 
			left->childPtrs[ iter ] = NULL;
		}
		
		// Case 2 - valueLocation is equal to the minDegree 
		else if( valueLocation == minDegree ){
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			// Get the left values
			for( ; iter < minDegree; iter++ ){
				
				left->values[ left->count ] = y->values[iter];
				left->childPtrs[ left->count ] = y->childPtrs[iter];
				left->count++;				
			}
			
			// Make the left equal to the current right
			left->childPtrs[ left->count ] = y->childPtrs[iter];
			
			// Make the current node's first value as the newValue 
			values[0] = newValue;
			count++;
			
			// Put the rest in the new right child 
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				left->childPtrs[ right->count ] = y->childPtrs[iter];
				right->count++;				
			}	

			left->childPtrs[ right->count ] = y->childPtrs[iter];
			
		}
		
		// Case 3 - valueLocation is greater than the minDegree 
		else{
			
			// In this case, the value to be inserted is in the left node
			unsigned int iter = 0;
			
			// Get the left values
			for( ; iter < minDegree; iter++ ){
				
				left->values[iter] = y->values[iter];
				left->childPtrs[ iter ] = y->childPtrs[iter];
				left->count++;				
			}

			// The middle value is the value at min degree
			// Make the current node's first value as the middle 
			values[0] = y->values[iter];
			iter++;	count++;

			//COUT << iter << " " << y->values[iter] << ENDL;
			while( iter < maxDegree - 1 && y->values[iter] < newValue ){
				
				right->values[ right->count ] = y->values[iter];
				right->childPtrs[ right->count ] = y->childPtrs[iter];
				iter++;	right->count++;
			}	

			// Now we have found the location for the new Value
			//COUT << iter - minDegree - 1 << " " << newValue << ENDL;			
			right->values[iter - minDegree - 1] = newValue;
			right->childPtrs[ iter - minDegree - 1 ] = y->childPtrs[iter];
			right->count++;
			
			// Get the rest of the left
			for( ; iter < maxDegree - 1; iter++ ){
				
				right->values[ right->count ] = y->values[iter];
				right->childPtrs[ right->count ] = y->childPtrs[iter];
				right->count++;				
				
			}		
			
		}
		
		// Set the parent's node 0 to left, and 1 to right
		childPtrs[0] = left;
		childPtrs[1] = right;
	} */
};


#endif