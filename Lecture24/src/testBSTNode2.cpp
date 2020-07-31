#include "../include/BSTNode1.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the nodes
	BSTNode< char > node1( 'M' );
	
	// Set the left and right pointers using addresses
	node1.left = new BSTNode< char >( 'B' );
	node1.right = new BSTNode< char >( 'R' );
	
	COUT << node1.data << ENDL;
	
	// Must de-reference the pointer to get data
	COUT << node1.left->data << ENDL;
	COUT << node1.right->data << ENDL;
	
	// Deliberate segmentation fault here 
	COUT << node1.left->left->data << ENDL;
	
	return 0;
}