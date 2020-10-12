#include "../classes/BTree5.h"

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
	
	COUT << "\n------ Deliberately Wrong Results to Motivate Rise and Merge ----------\n";
	COUT << "Inserting 50 into bTree1 gives bad results since we haven't merged. 50 not in result\n";
	bTree1.insert( 50 );
	// Print the Traversal
	bTree1.traversal();
	COUT << ENDL;	
	
	COUT << "\nInserting Irish into the current tree gives bad results since we haven't merged\n";
	bTree2.insert( std::string( "Irish" ) );
	// Print the Traversal
	bTree2.traversal();
	COUT << ENDL;		
	return 0;
		
}