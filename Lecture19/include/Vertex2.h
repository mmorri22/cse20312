#ifndef VERTEX2_H
#define VERTEX2_H

#include "DynArr.h"
#include "Edge.h"

#include <iostream>

template<class T>
class Vertex{

	private:
	
		DynArr< Edge > edges;	// Contains all outgoing edges
		T data;					// The data stored in the Vertex
		bool valid;				// Mark as valid - False for Lazy Deletion
		
	public:
	
		// Default Constructor
		Vertex( ) : edges(), data( ), valid( true ) {}
	
		// Overloaded Constructor
		Vertex( const T& dataIn ) : edges(), data( dataIn ), valid( true ) {}
		
		// Get the Vertex data
		T get_vertex_value() const{
			
			return data;
		}
		
		// Set the Vertex Value
		void set_vertex_value(const T& dataIn){
			
			data = dataIn;
		}
		
		// Adding an Edge to a Vertex
		void add_edge( unsigned int destin, int weight ){
			
			// If not, put the edge on the back of the array
			edges.push_back( Edge(destin, weight) );
			
		}
		
		// Remove the edge to an input destination
		bool remove_edge( unsigned int edgeLoc ){
			
			bool deleted = false;
			
			for(unsigned int i = 0; i < edges.length(); i++){
				
				if( edges[i].destin == edgeLoc ){
					edges.erase(i);
					deleted = true;
					break;
				}
			}
			
			return deleted;
		}
		
		// Overloaded Friend Output Operator
		friend std::ostream& operator<<( std::ostream& output, const Vertex<T>& theVert ){
			
			// If the vertex is valid
			if( theVert.valid ){
			
				// Print the data element first
				output << "[" << theVert.data << ": ";
				
				// 
				for( long unsigned int iter = 0; iter < theVert.edges.length(); iter++ ){
					
					// Print the destination
					output << "{" << theVert.edges[iter].destin << ", ";
					
					// Print the weight
					output << theVert.edges[iter].weight << "} ";
					
				}
				output << "]";
			
			}
			// If the vertex is not valid, indicate Lazy Deletion
			else{
				output << "[DELETED]";
			}
			
			return output;
		}
		
};

#endif