/**********************************************
* File: procMatrix.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Example of how complicated setting matricies 
* procedurally can be. If you know the elements in advance
* use the example in matrix.cpp
*
* Lecture 04 - Slide 17
**********************************************/

#include <iostream>
#include <cstdlib>

// M x N matrix
#define M 10
#define N 10

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	int** matrix = new int*[M];
	
	for( long unsigned int iter = 0; iter < N; iter++ ){
		
		matrix[iter] = new int[N];
		
	}
	
	/* Row 1 */
	matrix[0][0] = matrix[0][1] = matrix[0][2] = matrix[0][3] = matrix[0][4] = 1;
	matrix[0][5] = matrix[0][6] = 0;
	matrix[0][7] = matrix[0][8] = matrix[0][9] = 1;
	
	/* Row 2 */
	matrix[1][0] = matrix[1][6] = matrix[1][8] = 0;
	matrix[1][1] = matrix[1][2] = matrix[1][3] = matrix[1][4] = matrix[1][5] = 1;
	matrix[1][7] = matrix[1][9] = 1;
	
	/* Row 3 */
	matrix[2][0] = matrix[2][1] = matrix[2][3] = matrix[2][7] = matrix[2][8] = 0;
	matrix[2][2] = matrix[2][4] = matrix[2][5] = matrix[2][6] = matrix[2][9] = 1;

	/* Row 4 */
	matrix[3][1] = matrix[3][5] = matrix[3][8] = 0;
	matrix[3][0] = matrix[3][2] = matrix[3][3] = matrix[3][4] = matrix[3][6] = 1;
	matrix[3][7] = matrix[3][9] = 1;

	/* Row 5 */
	matrix[4][3] = matrix[4][7] = matrix[4][9] = 1;
	matrix[4][0] = matrix[4][1] = matrix[4][2] = matrix[4][4] = matrix[4][5] = 1;
	matrix[4][6] = matrix[4][8] = 1;
	
	/* Row 6 */
	matrix[5][1] = matrix[5][5] = matrix[5][6] = matrix[5][9] = 0;
	matrix[5][0] = matrix[5][2] = matrix[5][3] = matrix[5][4] = matrix[5][7] = matrix[5][8] = 1;
	
	/* Row 7 */
	matrix[6][4] = matrix[6][7] = matrix[6][9] = 1;
	matrix[6][0] = matrix[6][1] = matrix[6][2] = matrix[6][3] = matrix[6][5] = 0;
	matrix[6][6] = matrix[6][8] = 0;
	
	/* Row 8 */
	matrix[7][0] = matrix[7][8] = matrix[7][9] = 0;
	matrix[7][1] = matrix[7][2] = matrix[7][3] = matrix[7][4] = matrix[7][5] = 1;
	matrix[7][6] = matrix[7][7] = 1;
	
	/* Row 9 */
	matrix[8][5] = matrix[8][6] = 0;
	matrix[8][0] = matrix[8][1] = matrix[8][2] = matrix[8][3] = matrix[8][4] = 1;
	matrix[8][7] = matrix[8][8] = matrix[8][9] = 1;
	
	/* Row 10 */
	matrix[9][2] = matrix[9][5] = matrix[9][6] = matrix[9][9] = 1;
	matrix[9][0] = matrix[9][1] = matrix[9][3] = matrix[9][4] = matrix[9][7] = matrix[9][8] = 0;

	for(unsigned int iter = 0; iter < M; iter++ ){
		
		COUT << "{";
		
		for(unsigned int jter = 0; jter < N; jter++ ){
			
			COUT << matrix[iter][jter] << " ";
		}
		
		COUT << "}" << ENDL;
	}

	
	return 0;
	
}