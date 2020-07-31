#include "../include/BST7.h"
#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the Tree
	BST< int > theTree;
	
	theTree.Insert( 15 );	theTree.Insert( 10 );	theTree.Insert( 6 );
	theTree.Insert( 25 );	theTree.Insert( 30 );	theTree.Insert( 12 );
	theTree.Insert( 5 );
	
	// Print the Trees 
	COUT << "theTree : \n" << theTree << ENDL;
	
	// Print the Minimum Value 
	COUT << "The Max Height is: " << theTree.maxHeight() << ENDL << ENDL;
	
	// Delete 6 and repear
	theTree.remove( 6 );
	COUT << "theTree : \n" << theTree << ENDL;
	COUT << "The Max Height is: " << theTree.maxHeight() << ENDL << ENDL;
	
	return 0;	
	
}