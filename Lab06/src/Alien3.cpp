#include "../include/Graph.h"
#include "../include/DynArr.h"
#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string

int main(){
	
	DynArr < STRING > words;

	words.push_back( "wt" );	
	words.push_back( "werfghabit" );
	
	COUT << "Alien Words: ";
	for( unsigned int iter = 0; iter < words.size(); iter++ ){
		
		COUT << words[ iter ] << " ";
	}
	
	COUT << ENDL << ENDL;
	
	// Create the character Graph to solve the problem
	Graph< char > AlienLanguage;
	
	// Pair the character with its parent
	DynArr< std::pair<char, int> > parents; 
	
	for( unsigned int iter = 0; iter < words.size(); iter++ ){
	
		for( long unsigned int jter = 0; jter < words[iter].size(); jter++ ){
			
			// If the graph does not contain a vertex with the character
			if( !AlienLanguage.contains_vertex_data( words[iter].at(jter) ) ){
				
				// Add that vertex to the graph
				AlienLanguage.add_vertex( words[iter].at(jter) );
				
				// Add a new location on parents. -1 means no parent, which is fine for now
				parents.push_back( {words[iter].at(jter), -1} );
				
			}
			
			// Meaning there are at least two characters in the word
			if( jter > 0 && words[iter].at(jter) != words[iter].at(jter - 1) ){
				
				// Set the origin as the character that is one behind (jter - 1)
				int origin = AlienLanguage.find_data_index( words[iter].at(jter - 1) );
				
				// Set the destination as the current character (jter)
				int destin = AlienLanguage.find_data_index( words[iter].at(jter) );
				
				// First, we check to make sure we don't add a duplicate character (origin != destin)
				// Second, we use connected from Lecture 22 to see if we they are not connected
				if( origin != destin && !AlienLanguage.connected( origin, destin ) ){
					
					// Add an edge from origin (jter - 1) to destination (jter)
					AlienLanguage.add_edge( origin, destin, 1 );
					
					// Update the parent if the parent does not exist
					if( parents[destin].second == -1 ){
					
						// Update the destination's parent as the origin
						parents[destin].second = origin;
					
					}
				}
			}
			
			// Meaning there are at least three characters, and the most recent two are not duplicates
			if( jter > 1 && words[iter].at(jter) != words[iter].at(jter - 1) ){
				
				// Set the destination as the current character (jter)
				int destin = AlienLanguage.find_data_index( words[iter].at(jter) );
				
				// Obtain the origin of the previous parent
				int origin = parents[destin].second;
				
				// If that edge exists, remove it
				if( origin != -1 && AlienLanguage.does_edge_exist( origin, destin ) ){
					
					// Remove the old edge
					AlienLanguage.remove_edge( origin, destin );
					
					// Get the vertex location of jter-1
					int updatedOrigin = AlienLanguage.find_data_index( words[iter].at(jter - 1) ); 
					
					// Update the destination's parent as the origin
					parents[destin].second = updatedOrigin;
					
				}
			}
			
		}
	}
	
	
	COUT << "Remaining Original Graph:" << ENDL;
	COUT << ENDL << AlienLanguage << ENDL;
	
	// COUT << ENDL << parents << ENDL;
	COUT << "Parent Array Values:" << ENDL;
	for( unsigned int iter = 0; iter < parents.size(); iter++ ){
		
		COUT << parents[iter].first << " " << parents[iter].second << ENDL;
		
	}
	
	// Put the solution into a Graph
	Graph <char> Solution;
	
	// Put in the characters into the Solution Graph
	for( unsigned int iter = 0; iter < parents.size(); iter++ ){
		
		Solution.add_vertex( parents[iter].first );
		
	}
	
	// Next, put in the edges into the Solution Graph 
	for( unsigned int iter = 0; iter < parents.size(); iter++ ){
		
		if( parents[iter].second != -1 ){
		
			Solution.add_edge( (unsigned int)parents[iter].second, iter, 1 );
		
		}
		
	}	
	
	COUT << ENDL << "Solution Graph:" << ENDL;
	COUT << Solution << ENDL;
	
	return 0;
	
	
}