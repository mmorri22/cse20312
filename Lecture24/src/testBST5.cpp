#include "../include/BST6.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the Tree
	BST< int > theTree;
	
	theTree.Insert( 15 );
	theTree.Insert( 10 );
	theTree.Insert( 6 );
	theTree.Insert( 25 );
	theTree.Insert( 30 );
	theTree.Insert( 12 );
	
	// Print the Trees 
	COUT << "theTree : \n" << theTree << ENDL;
	
	return 0;
}