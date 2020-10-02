#include "../include/AVLTree.h"
#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

template< class T >
void testInsert( AVLTree<T>& theTree, const T& theValue ){
	
	COUT << "Inserting " << theValue << "...\n"; 
	
	theTree.Insert( theValue );
	COUT << theTree << ENDL << ENDL;
}

template< class T >
void testRemove( AVLTree<T>& theTree, const T& theValue ){
	
	COUT << "Deleting " << theValue << "...\n"; 
	
	// If we return false, element was not in the tree
	if(!theTree.remove( theValue )){
		
		COUT << theValue << " is not in the Tree " << ENDL << ENDL;
	}
	
	// Otherwise, print the In, Pre, Post, and Level Order Traversals
	else{
		COUT << "Successful Deletion: " << ENDL;
		COUT << theTree << ENDL << ENDL;
	}
	
}

int main(){
	
	// Initialize the Tree
	AVLTree< int > theTree;
	
	testInsert( theTree, 15 );	testInsert( theTree, 10 );	testInsert( theTree, 6 );
	testInsert( theTree, 25 );	testInsert( theTree, 30 );	testInsert( theTree, 12 );
	testInsert( theTree, 5 );	testInsert( theTree, 4 );	testInsert( theTree, 3 );
	
	// Test Inherited Containts
	COUT << "Testing contains '12' : " << theTree.contains(12) << ENDL;
	COUT << "Testing contains '25' : " << theTree.contains(25) << ENDL;
	COUT << "Testing contains '40' : " << theTree.contains(40) << ENDL;	
	COUT << "Testing contains '30' : " << theTree.contains(30) << ENDL;		
	COUT << "Testing contains '-30' : " << theTree.contains(-30) << ENDL;
	COUT << "Testing contains '15' : " << theTree.contains(15) << ENDL << ENDL;
	
	// Test Inherited findMin
	COUT << "Minimum Value is: " << theTree.findMin()->data << ENDL;
	
	// Test Inherited findMax 
	COUT << "Maximum Value is: " << theTree.findMax()->data << ENDL << ENDL;
	
	// Test Remove
	testRemove( theTree, 25 );		testRemove( theTree, 12 );
	testRemove( theTree, 15 );		testRemove( theTree, -30 );
	testRemove( theTree, 30 );		testRemove( theTree, 6 );
	testRemove( theTree, 10 );		testRemove( theTree, 5 );
	testRemove( theTree, 4 );		testRemove( theTree, 3 );
	
	return 0;	
	
}