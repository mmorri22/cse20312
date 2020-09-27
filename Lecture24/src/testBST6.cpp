#include "../include/BST6.h"
#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Initialize the Tree
	BST< int > theTree;
	
	theTree.Insert( 15 );	theTree.Insert( 10 );	theTree.Insert( 6 );
	theTree.Insert( 25 );	theTree.Insert( 30 );	theTree.Insert( 12 );
	
	// Print the Trees 
	COUT << "theTree : \n" << theTree << ENDL << ENDL;
	
	COUT << "Testing contains '12' : " << theTree.contains(12) << ENDL;
	COUT << "Testing contains '25' : " << theTree.contains(25) << ENDL;
	COUT << "Testing contains '40' : " << theTree.contains(40) << ENDL;	
	COUT << "Testing contains '30' : " << theTree.contains(30) << ENDL;		
	COUT << "Testing contains '-30' : " << theTree.contains(-30) << ENDL;
	COUT << "Testing contains '15' : " << theTree.contains(15) << ENDL << ENDL;
	
	// Print the Minimum Value 
	COUT << "Minimum Value is: " << theTree.findMin()->data << ENDL;
	
	// Print the Maximum Value 
	COUT << "Maximum Value is: " << theTree.findMax()->data << ENDL;
	
	return 0;	
	
}