#include "../classes/BTree7.h"

#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Establish a B-Tree Node with Order 3 
	BTree< int > bTree1( 3 );
	
	COUT << "------------Printing the already tested inputs----------------" << ENDL;
	
	// Insert one element 
	bTree1.insert( 10 );
	bTree1.insert( 30 );
	bTree1.insert( 20 );
	bTree1.insert( 40 );
	bTree1.insert( 5 );
	bTree1.insert( 35 );
	bTree1.insert( 25 );
	bTree1.insert( 50 );
	COUT << "Pre-Second Level Split:" << ENDL;
	bTree1.traversal();
	COUT << ENDL;
	
	
	
	COUT << ENDL << "-----Now we insert into the BTrees requiring multiple splits-------" << ENDL;
	bTree1.insert( 55 );	
	bTree1.traversal();	
	COUT << ENDL;
	
	return 0;
		
}