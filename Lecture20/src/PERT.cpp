#include "../include/Graph6.h"
#include <iostream>

int main(){
	
	Graph< char > theGraph;
	
	theGraph.add_vertex( 'A' );
	theGraph.add_vertex( 'B' );
	theGraph.add_vertex( 'C' );
	theGraph.add_vertex( 'D' );
	theGraph.add_vertex( 'E' );
	theGraph.add_vertex( 'F' );
	theGraph.add_vertex( 'G' );
	theGraph.add_vertex( 'H' );
	
	// Nodes from 0, A
	theGraph.add_edge( 0, 2, 1 );
	theGraph.add_edge( 0, 4, 1 );

	// Nodes from 1, B	
	theGraph.add_edge( 1, 0, 1 );
	theGraph.add_edge( 1, 4, 1 );
	

	// Nodes from 3, D 
	theGraph.add_edge( 3, 0, 1 );
	
	// Nodes from 5, F 
	theGraph.add_edge( 5, 1, 1 );
	theGraph.add_edge( 5, 0, 1 );
	theGraph.add_edge( 5, 3, 1 );
	theGraph.add_edge( 5, 6, 1 );
	
	// Nodes from 6, G 
	theGraph.add_edge( 6, 2, 1 );
	theGraph.add_edge( 6, 4, 1 );
	
	// Nodes from 7, H 
	theGraph.add_edge( 6, 2, 1 );
	
	// Print results:
	std::cout << "Original Graph:\n" << theGraph << std::endl;
	
	// Run Depth-First Search
	Graph<char> topSort = theGraph.TopSort();
	std::cout << "\nTopological Sort Graph:\n" << topSort << std::endl;
	
	return 0;
}
