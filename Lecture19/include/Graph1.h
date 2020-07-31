#ifndef GRAPH1_H
#define GRAPH1_H

#include "Vertex2.h"
#include "DynArr.h"
#include <iostream>

template<class T>
class Graph{
	
	private:
		DynArr< Vertex< T > > vertices;	// Adjacency Lisy
		
	public:
		// Constructor
		Graph( ) : vertices() {}
		
		// Add a vertex prior to any edges
		void add_vertex( T vertexData ){
			
			Vertex<T> theVertex( vertexData );
			vertices.push_back( theVertex );
		}
		
		// Add Edge from Origin to Destination, with weight
		void add_edge(unsigned int origin, unsigned int destin, int weight ){
			
			if( origin < vertices.length() && destin < vertices.length() ){
			
				vertices[origin].add_edge( destin, weight );
		
			}
		}
		
		// Overloaded Operator
		friend std::ostream& operator<<( std::ostream& output, const Graph<T>& theGraph ){
			
			for( unsigned int iter = 0; iter < theGraph.vertices.length(); iter++ ){
				
				output << iter << ": " << theGraph.vertices[ iter ] << std::endl;
				
			}
			
			return output;
		}
};

#endif
