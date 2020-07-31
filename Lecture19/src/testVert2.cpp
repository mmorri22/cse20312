#include <iostream>
#include "../include/Vertex2.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Four Vertices for Seven Bridges of Koningsberg
	Vertex< std::string > vertex0( "Top River Bank" );
	Vertex< std::string > vertex1( "Left Island" );
	Vertex< std::string > vertex2( "Bottom River Bank" );
	Vertex< std::string > vertex3( "Right Island" );
	
	// Create an Adjacency List 
	DynArr< Vertex< std::string > > adjList;
	
	// Push the elements onto the List
	adjList.push_back( vertex0 );
	adjList.push_back( vertex1 );
	adjList.push_back( vertex2 );
	adjList.push_back( vertex3 );
	
	// Add the Bridge Edges
	// Can cross in either direction
	// Two bridges go from 0 to 1 and one from 0 to 3
	adjList[ 0 ].add_edge( 1, 1 );	adjList[ 0 ].add_edge( 1, 1 );
	adjList[ 0 ].add_edge( 3, 1 );
	
	// Two bridges from 1 to 0, two from 1 to 2, and one from 1 to 3
	adjList[ 1 ].add_edge( 0, 1 );	adjList[ 1 ].add_edge( 0, 1 );
	adjList[ 1 ].add_edge( 2, 1 );	adjList[ 1 ].add_edge( 2, 1 );
	adjList[ 1 ].add_edge( 3, 1 );
	
	// Two bridges from 2 to 1, and one from 2 to 3
	adjList[ 2 ].add_edge( 1, 1 );	adjList[ 1 ].add_edge( 1, 1 );
	adjList[ 2 ].add_edge( 3, 1 );	
	
	// One bridge from 3 to 2, and One from 3 to 0
	adjList[ 3 ].add_edge( 2, 1 );	adjList[ 3 ].add_edge( 0, 1 );
	
	// Print the edges to the user
	for( unsigned int iter = 0; iter < adjList.length(); iter++ ){
		
		COUT << iter << ": " << adjList[ iter ] << ENDL;
		
	}
	COUT << ENDL;
	
	// Remove Edge from 1 to 2 and 2, 3
	adjList[ 1 ].remove_edge( 2 );
	adjList[ 2 ].remove_edge( 3 );
	
	// Print the edges to the user after removing the edges
	for( unsigned int iter = 0; iter < adjList.length(); iter++ ){
		
		COUT << iter << ": " << adjList[ iter ] << ENDL;
		
	}
	
	return 0;
	
}

