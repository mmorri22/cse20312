#include "../classes/BTree7.h"

#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Establish a B-Tree Node with Order 4
	BTree< std::string > bTree2( 4 );
	
	// Insert one element 
	bTree2.insert( std::string( "Data" ) );
	bTree2.insert( std::string( "Structures" ) );
	bTree2.insert( std::string( "puppy" ) );
	bTree2.insert( std::string( "class" ) );
	bTree2.insert( std::string( "B-Tree" ) );
	bTree2.insert( std::string( "Apple" ) );
	bTree2.insert( std::string( "zebra" ) );
	bTree2.insert( std::string( "Art" ) );
	bTree2.insert( std::string( "Bananas" ) );
	bTree2.insert( std::string( "Aardvark" ) );
	bTree2.insert( std::string( "kitten" ) );
	bTree2.insert( std::string( "design" ) );
	bTree2.insert( std::string( "fighting" ) );
	bTree2.insert( std::string( "pointer" ) );
	bTree2.insert( std::string( "Army" ) );	
	// Print the Traversal
	COUT << "Pre-Second Level Split:" << ENDL;
	bTree2.traversal();
	COUT << ENDL;
	
	COUT << ENDL << "-----Now we insert into the BTrees requiring multiple splits-------" << ENDL;
	bTree2.insert( std::string( "echo" ) );
	bTree2.traversal();	
	COUT << ENDL;
	return 0;
		
}