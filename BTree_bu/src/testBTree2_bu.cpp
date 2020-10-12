#include "../classes/BTree2.h"

#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Establish a B-Tree Node with Order 3 
	BTree< int > bTree1( 4 );
	
	// Insert elements 
	bTree1.Insert( 10 );
	bTree1.traversal();
	bTree1.Insert( 20 );
	bTree1.traversal();
	bTree1.Insert( 5 );
	bTree1.traversal();
	bTree1.Insert( 18 );
	bTree1.traversal();
	bTree1.Insert( 99 );
	bTree1.traversal();
	
	COUT << ENDL;
	
	// Establish a B-Tree Node with Order 5
	BTree< std::string > bTree2( 4 );
	
	bTree2.Insert( "Data" );
	bTree2.Insert( "Structures" );
	bTree2.Insert( "class" );
	bTree2.traversal();
	bTree2.Insert( "puppy" );
	bTree2.traversal();
	bTree2.Insert( "Notre" );
	bTree2.traversal();
	bTree2.Insert( "Dame" );
	
	bTree2.traversal();

	COUT << ENDL;
	
}