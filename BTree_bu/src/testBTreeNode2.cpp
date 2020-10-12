#include "../include/BTreeNode2.h"
#include <string>

int main(){
	
	// Establish B-Tree Nodes with Maximum Degree of 3
	BTreeNode< int > bTreeNode1( 3 );
	BTreeNode< int > bTreeNode2( 3 );
	BTreeNode< std::string > bTreeNode3( 3 );
	
	// Set the first value as 7 and the second value as 10
	bTreeNode1.values[0] = 7;	bTreeNode1.values[1] = 10;
	bTreeNode1.count = 2;
	
	// Find the location where 11 should be placed
	COUT << "bTreeNode1 11 should be at " << bTreeNode1.findValue( 11 ) << ENDL;
	
	// Set the first value as 6 and the second value as 7
	bTreeNode2.values[0] = 6;	bTreeNode2.values[1] = 7;
	bTreeNode2.count = 2;
	
	// Find the location where 11 should be placed
	COUT << "bTreeNode2 5 should be at " << bTreeNode2.findValue( 5 ) << ENDL;

	// Set the first value as Aardvark and the second value as Zebra
	bTreeNode3.values[0] = "Aardvark";	bTreeNode3.values[1] = "Zebra";
	bTreeNode3.count = 2;
	
	// Find the location where 13 should be placed
	COUT << "bTreeNode3 'Manatee' should be at " << bTreeNode3.findValue( "Manatee" ) << ENDL;

	return 0;
}