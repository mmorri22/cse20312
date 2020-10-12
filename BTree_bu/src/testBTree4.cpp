#include "../classes/BTree4.h"

#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Establish a B-Tree Node with Order 3 
	BTree< int > bTree1( 3 );
	
	// Insert one element 
	bTree1.insert( 10 );
	bTree1.insert( 30 );

	COUT << "Pre-Split:" << ENDL;
	bTree1.traversal();
	
	COUT << "Post-Split:" << ENDL;
	bTree1.insert( 20 );
	
	// Print the Traversal
	bTree1.traversal();
	COUT << ENDL;
	
	// Establish a B-Tree Node with Order 4
	BTree< std::string > bTree2( 4 );
	
	// Insert one element 
	bTree2.insert( std::string( "Data" ) );
	bTree2.insert( std::string( "Structures" ) );
	bTree2.insert( std::string( "puppy" ) );

	COUT << "Pre-Split:" << ENDL;
	bTree2.traversal();
	
	COUT << "Post-Split:" << ENDL;
	bTree2.insert( std::string( "class" ) );
	
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;
	
	return 0;
		
}