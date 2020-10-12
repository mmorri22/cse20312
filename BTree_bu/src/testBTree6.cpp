#include "../classes/BTree6.h"

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
	
	COUT << "Post-Split 2:" << ENDL;
	bTree1.insert( 40 );
	bTree1.insert( 5 );
	bTree1.insert( 35 );
	bTree1.insert( 25 );
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
	
	
	COUT << "Post-Split 2:" << ENDL;
	bTree2.insert( std::string( "B-Tree" ) );
	bTree2.insert( std::string( "Apple" ) );
	bTree2.insert( std::string( "zebra" ) );		
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;
	
	COUT << "\n------ With Merge, these inserts are fixed ----------\n";
	bTree1.insert( 50 );
	// Print the Traversal
	bTree1.traversal();
	COUT << ENDL;	
	
	bTree2.insert( std::string( "Irish" ) );
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;

	bTree2.insert( std::string( "Art" ) );
	bTree2.insert( std::string( "Bananas" ) );
	bTree2.insert( std::string( "Aardvark" ) );
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;
	
	// Fill the rest of the tree 
	bTree2.insert( std::string( "kitten" ) );
	bTree2.insert( std::string( "design" ) );
	bTree2.insert( std::string( "fighting" ) );
	bTree2.insert( std::string( "pointer" ) );	
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;		
	return 0;
		
}