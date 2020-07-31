#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"

#include <iostream>
#include <fstream>

template<class T>
class Graph{
	
	private:
	
		std::vector< Vertex< T > > vertices;
		bool bi_directional;
	
	public:
	
		Graph( bool bi_direct ) : vertices(), bi_directional(bi_direct) {}
		
		
		void add_vertex( T vertexData ){
			
			Vertex<T> theVertex( vertexData );
			
			vertices.push_back( theVertex );
			
		}
		
		
		void add_edge(unsigned int origin, unsigned int destin, int weight ){
			
			if( origin < vertices.size() && destin < vertices.size() ){
			
				vertices.at(origin).add_edge( destin, weight );
				
				if( bi_directional ){
					
					vertices.at(destin).add_edge( origin, weight );
				}
			}
			else{
				std::cout << "Unable to add edge. Edge outside graph bounds\n";
			}
		}
		
		
		bool get_vertex_value( unsigned int vertex, T& value ){
			
			bool validVertex = false;
			
			if( vertex < vertices.size() ){
				
				validVertex = true;
				value = vertices.at(vertex).get_vertex_value();
				
			}
			
			return validVertex;
			
		}
		
		
		void set_vertex_value( unsigned int vertex, T& value ){
						
			if( vertex < vertices.size() ){
				
				value = vertices.at(vertex).set_vertex_value( value );
				
			}
						
		}
		
		bool adjacent( unsigned int origin, unsigned int destin ){
			
			if( origin < vertices.size() && destin < vertices.size() ){
				
				for(unsigned int i = 0; i < vertices.at(origin).num_edges(); i++){
					
					if(vertices.at(origin).get_edge().destin == destin){
						
						return true;
					}
				}
				
				return false;
			}
			else{
				
				return false;
			}
			
		}
		
		
		void neighbors( unsigned int vertex ){
			
			if( vertex < vertices.size() ){
				
				std::cout << "Vertex " << vertex << " had edges going to: ";
				
				for(unsigned int i = 0; i < vertices.at(vertex).num_edges(); i++){
					
					std::cout << vertices.at(vertex).get_edge().destin << ", ";

				}	
				std::cout << std::endl;
				
			}
			else{
				
				std::cout << vertex << " exceeds graph capacity\n";
			}
			
		}


		bool get_edge_value( unsigned int origin, unsigned int destin, int& weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				vertices.at(origin).get_edge_value( destin, weight );
				return true;
				
			}
			
			return false;
				
		}

		bool set_edge_value( unsigned int origin, unsigned int destin,
			int weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				vertices.at(origin).set_edge_value( destin, weight );
				
				if( bi_directional ) {
					
					vertices.at(destin).set_edge_value( origin, weight );

				}
				
				return true;
				
			}
			
			return false;
				
		}
		
		
		void remove_edge( unsigned int origin, unsigned int destin){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				vertices.at(origin).remove_edge( destin );
				
				if( bi_directional ) {
					
					vertices.at(destin).remove_edge( origin );

				}
				
				return;
				
			}
			
			return;
				
		}
		
	
		friend std::ostream& operator<<( std::ostream& out, const Graph<T>& g){
			
			for( unsigned int i = 0; i < g.vertices.size(); i++ ){
				
				out << "{" << i << ", " << g.vertices.at(i).get_vertex_value() << "} ";
				
				for( unsigned int j = 0; j < g.vertices.at(i).num_edges(); j++ ){
					
					Edge tempEdge = g.vertices.at(i).get_edge(j);
					
					std::cout << "(" << tempEdge.destin << ", ";
					std::cout << tempEdge.weight << "), ";
				}
				
				out << std::endl;
			}
			
			return out;
		}
	
};

#endif