#ifndef LCS_H
#define LCS_H

#include <string>
#include <iostream>

#define STRING std::string
#define COUT std::cout
#define ENDL std::endl

void printMatrix( unsigned int** matrix, long unsigned rows, long unsigned cols ){
	
	for( long unsigned int iter = 0; iter < rows; iter++ ){
		
		for( long unsigned int jter = 0; jter < cols; jter++ ){
			
			COUT << matrix[iter][jter] << " ";
			
		}
		COUT << ENDL;
	}
	
	
}

unsigned int LCS( STRING& string1, STRING& string2 ){
	
	unsigned int** matrix = (unsigned int **)malloc( (string1.size() + 1) * sizeof(unsigned int*) );
	
	unsigned int result = 0;
	
	for( long unsigned int iter = 0; iter < string1.size() + 1; iter++ ){
		
		matrix[iter] = (unsigned int *)malloc( (string2.size() + 1) * sizeof(unsigned int) );
		
	}
	
	// Set all values to 0
	for( long unsigned int iter = 0; iter < string1.size() + 1; iter++ ){
	
		for( long unsigned int jter = 0; jter < string2.size() + 1; jter++ ){
			
			matrix[iter][jter] = 0;
		}
	}
		
	COUT << "Initial Matrix" << ENDL;
	
	printMatrix( matrix, string1.size() + 1, string2.size() + 1 );
	
	// Perform the algorithm 
	for( long unsigned int iter = 0; iter < string1.size(); iter++ ){
		
		for( long unsigned int jter = 0; jter < string2.size(); jter++ ){
		
			if( string1.at(iter) == string2.at(jter) ){
				
				matrix[iter + 1][ jter + 1 ] = matrix[iter][ jter ] + 1;
				
				if( matrix[iter + 1][ jter + 1 ] > result ){
					
					result = matrix[iter + 1][ jter + 1 ];
				}

			}
			else{
				
				if( matrix[ iter ][ jter + 1 ] > matrix[ iter + 1 ][ jter ] ){
					
					matrix[iter + 1][ jter + 1 ] = matrix[ iter ][ jter + 1 ];
				}
				else{
					
					matrix[iter + 1][ jter + 1 ] = matrix[ iter + 1 ][ jter ];
				}
			}
		}
	}
	
	COUT << "Final Matrix" << ENDL;
	
	printMatrix( matrix, string1.size() + 1, string2.size() + 1 );
	
	return result;
}


#endif