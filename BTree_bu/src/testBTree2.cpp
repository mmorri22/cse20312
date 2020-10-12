#include "../classes/BTree2.h"

#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Establish a B-Tree Node with Order 3 
	BTree< int > bTree1( 3 );
	
	// Insert one element 
	bTree1.insert( 1 );
	
	// Print the Traversal
	bTree1.traversal();
	COUT << ENDL;
	
	// Establish a B-Tree Node with Order 4
	BTree< std::string > bTree2( 4 );
	
	// Insert one element 
	bTree2.insert( std::string( "Data" ) );
	
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;
	
	return 0;
		
}