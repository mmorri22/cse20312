#include "../include/Graph.h"
#include "../include/DynArr.h"
#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string

int main(){
	
	DynArr < STRING > words;
	
	words.push_back( "wrt" );
	words.push_back( "wrf" );
	words.push_back( "ett" );
	words.push_back( "rftt" );
	words.push_back( "wer" );
	words.push_back( "eftt" );
	
	COUT << "Alien Words: ";
	for( unsigned int iter = 0; iter < words.size(); iter++ ){
		
		COUT << words[ iter ] << " ";
	}
	
	COUT << ENDL << ENDL;
	
	Graph< char > AlienLanguage;
	
	for( unsigned int iter = 0; iter < words.size(); iter++ ){
	
		for( long unsigned int jter = 0; jter < words[iter].size(); jter++ ){
			
			if( !AlienLanguage.contains_vertex_data( words[iter].at(jter) ) ){
				
				AlienLanguage.add_vertex( words[iter].at(jter) );
				
			}
			
			if( jter > 0 ){
				
				int origin = AlienLanguage.find_data_index( words[iter].at(jter - 1) );
				int destin = AlienLanguage.find_data_index( words[iter].at(jter) );
				
				if( origin != destin && !AlienLanguage.connected( origin, destin ) ){
					
					AlienLanguage.add_edge( origin, destin, 1 );
					
				}
			}
			
			if( jter > 1 && words[iter].at(jter) != words[iter].at(jter - 1) ){
				
				int origin = AlienLanguage.find_data_index( words[iter].at(jter - 2) );
				int destin = AlienLanguage.find_data_index( words[iter].at(jter) );
								
				if( AlienLanguage.does_edge_exist( origin, destin ) ){
					
					AlienLanguage.remove_edge( origin, destin );
					
				}
			}
			
		}
	}
	
COUT << ENDL << AlienLanguage << ENDL;
	
	return 0;
	
	
}