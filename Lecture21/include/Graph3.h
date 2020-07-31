#ifndef GRAPH3_H
#define GRAPH3_H

#include "Vertex.h"
#include "DynArr.h"
#include "queue.h"
#include "stack.h"
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
		
		// Return the value with a Call by Reference
		// bool for if the vertex requested was valid
		bool get_vertex_value( unsigned int vertex, T& value ){
			
			if( vertex < vertices.length() ){
				
				value = vertices.at(vertex).get_vertex_value();
				return true;
			}
			
			return false;
			
		}
		
		// Set the value at a given vertex 
		// bool for if the vertex requested was valid
		bool set_vertex_value( unsigned int vertex, T& value ){
						
			if( vertex < vertices.length() ){
				
				value = vertices[vertex].set_vertex_value( value );
				return true;
			}			
			return false;
		}
		
		// Return the value with a Call by Reference
		// bool for if the origin and destination requested were valid
		bool get_edge_value( unsigned int origin, unsigned int destin, int& weight){
				
			if( origin < vertices.length() && destin < vertices.length() ){
				
				return vertices[origin].get_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Set the value at a given origin and destination 
		// bool for if the origin and destination requested were valid
		bool set_edge_value( unsigned int origin, unsigned int destin, int weight){
				
			if( origin < vertices.length() && destin < vertices.length() ){
				
				return vertices[origin].set_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Remove an edge
		bool remove_edge( unsigned int origin, unsigned int destin){
				
			// If the origin and destination are valid
			if( origin < vertices.length() && destin < vertices.length() ){
				
				// From the Origin vertex, remove the destination vertex
				return vertices[origin].remove_edge( destin );
			}
			
			return false;
		}
		
		
		void remove_vertex( unsigned int vertVal ){
			
			// First, perform Lazy Deletion on the vertex 
			vertices[ vertVal ].lazy_delete();
			
			// Next, go through each vertex and remove all edges with the destination to the vertex 
			for( unsigned int iter = 0; iter < vertices.length(); iter++ ){
				
				int jter = 0;
				
				// While the increment is less than the number of edges
				while( jter < vertices[iter].num_edges() ){
					
					// If the destination of the edge is the vertex we are removing
					if( vertices[iter].get_edge( jter ).destin == vertVal ){
						
						// Remove that edge
						vertices[iter].remove_edge( vertVal );
					}
					else{
						// Only increment jter is there is not any deletion
						jter++;
					}
				}
			}
		}
		
		void BFS( unsigned int destin ){
			
			// If Graph can't be search, inform user and return 
			// destin cannot be greater than the number of vertices
			// The number of vertices must not be 0
			if( destin >= vertices.length() || vertices.length() == 0){
				
				std::cout << destin << " is not a valid vertex location" << std::endl;
				
				return;
			}
			
			/* Create elements for the search */
			
			// queue to store the next vertex to evaluate
			queue< unsigned int > theQueue;
			
			// Keeping track if the vertex has been visited. Set all initially to false
			bool* visited = new bool[vertices.length()];
			for( unsigned int iter = 0; iter < vertices.length(); iter++ ){
				
				visited[iter] = false;
			}
			
			// Keeping track of the parents 
			unsigned int* parents = new unsigned int[vertices.length()];
			
			// Use this stack for the final path
			stack< unsigned int > finalPath;
			
			/* Initialize the search */
			bool found = false; 
			
			// Push the origin onto the Queue
			theQueue.push(0);
			
			// The origin has no parent, and the origin has been visited
			parents[0] = -1;
			
			// Set found to true if the origin is the destination
			if( destin == 0 ){
				found = true;
			}
			
			// While the element is not found and the queue is not empty
			while( !found && !theQueue.empty() ){
				
				// First step in BFS is to obtain and remove the front element from the queue 
				unsigned int vertex = theQueue.front();
				theQueue.pop();
				
				// Mark the vertex as visited
				visited[ vertex ] = true;
				
				// Iterate through each edge 
				for( unsigned int iter = 0; iter < vertices[ vertex ].num_edges(); iter++){
					
					// Get the destination from the edge
					unsigned int edgeDestin = vertices[ vertex ].get_edge( iter ).destin;
					
					// If the edge's destination matches our destination, we found the node
					if( edgeDestin == destin ){
						
						found = true;
						
						// Mark the destination's parent as vertex 
						parents[ edgeDestin ] = vertex;
						
						break;
					}
					
					// If the destination has not been visited
					else if( visited[ edgeDestin ] == false ) {
						
						// Push the destination onto the queue
						theQueue.push( edgeDestin );
						// Mark edgeDestin's parent as vertex
						parents[ edgeDestin ] = vertex;
						
					}
				}

			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from origin to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid BFS path from the 0 to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
		}

		// BFS with an origin and destination node
		void BFS( unsigned int origin, unsigned int destin ){
			
			// If Graph can't be search, inform user and return 
			// origin destin cannot be >= than the number of vertices
			// The number of vertices must not be 0
			if( origin >= vertices.length() || destin >= vertices.length() || vertices.length() == 0){
				
				std::cout << "Invalid BFS inputs" << std::endl;
				
				return;
			}
			
			/* Create elements for the search */
			
			// queue to store the next vertex to evaluate
			queue< unsigned int > theQueue;
			
			// Keeping track if the vertex has been visited. Set all initially to false
			bool* visited = new bool[vertices.length()];
			for( unsigned int iter = 0; iter < vertices.length(); iter++ ){
				
				visited[iter] = false;
			}
			
			// Keeping track of the parents 
			unsigned int* parents = new unsigned int[vertices.length()];
			
			// Use this stack for the final path
			stack< unsigned int > finalPath;
			
			/* Initialize the search */
			bool found = false; 
			
			// Push the origin onto the Queue
			theQueue.push( origin );
			
			// The origin has no parent, and the origin has been visited
			parents[ origin ] = -1;
			
			// Set found to true if the origin is the destination
			if( destin == origin ){
				found = true;
			}
			
			// While the element is not found and the queue is not empty
			while( !found && !theQueue.empty() ){
				
				// First step in BFS is to obtain and remove the front element from the queue 
				unsigned int vertex = theQueue.front();
				theQueue.pop();
				
				// Mark the vertex as visited
				visited[ vertex ] = true;
				
				// Iterate through each edge 
				for( unsigned int iter = 0; iter < vertices[ vertex ].num_edges(); iter++){
					
					// Get the destination from the edge
					unsigned int edgeDestin = vertices[ vertex ].get_edge( iter ).destin;
					
					// If the edge's destination matches our destination, we found the node
					if( edgeDestin == destin ){
						
						found = true;
						
						// Mark the destination's parent as vertex 
						parents[ edgeDestin ] = vertex;
						
						break;
					}
					
					// If the destination has not been visited
					if( visited[ edgeDestin ] == false ) {
						
						// Push the destination onto the queue
						// std::cout << "pushing " << edgeDestin << std::endl;
						theQueue.push( edgeDestin );
						// Mark edgeDestin's parent as vertex
						parents[ edgeDestin ] = vertex;
						
						visited[ edgeDestin ] = true;
					}
				}

			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from " << origin << " to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid BFS path from " << origin << " to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
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
