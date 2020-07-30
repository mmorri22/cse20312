/**********************************************
* File: helloCmdLine.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file prints the inputs after the executable
* in the command lind 
*
* Lecture 04 - Slide 16
**********************************************/

#include <iostream>

#define COUT std::cout
#define ENDL std::endl

// Main Driver Function
int main(int argc, char** argv){
	
	/* Error Checking */
	if(argc < 2){
		COUT << "Not enough inputs on command line" << ENDL;
		exit(-1);
	}
	
	for( int iter = 0; iter < argc; iter++ ){

		COUT << "argv[" << iter << "] = " << *(argv + iter) << ENDL;
	}

	return 0;
}
