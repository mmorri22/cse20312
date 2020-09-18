#include <iostream>
#include <cstdlib>

// M x N matrix
#define M 10
#define N 10

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Brace Initializer Lists
	int matrix[M][N] =
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 }
	}; 

	for(unsigned int iter = 0; iter < M; iter++ ){
		
		COUT << "{";
		
		for(unsigned int jter = 0; jter < N; jter++ ){
			
			COUT << matrix[iter][jter] << " ";
		}
		
		COUT << "}" << ENDL;
	}

	
	return 0;
	
}