#include "../include/BSTNode1.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the nodes
	BSTNode< char > node1( 'M' );
	BSTNode< char > node2( 'B' );
	BSTNode< char > node3( 'R' );
	
	// Set the left and right pointers using addresses
	node1.left = &node2;
	node1.right = &node3;
	
	COUT << node1.data << ENDL;
	
	// Must de-reference the pointer to get data
	COUT << node1.left->data << ENDL;
	COUT << node1.right->data << ENDL;
	
	return 0;
}