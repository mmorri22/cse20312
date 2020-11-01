#include "../include/SplayTree.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


void printSplayRoot(SplayTree< void * >& cacheSplay){
	
	std::cout << "Location " << cacheSplay.returnRootVal() << " contains the value ";
	
	std::cout << *( (int *)(cacheSplay.returnRootVal()) );
	
}

int main(){
	
	// Seed the Random Number Generator
	srand ( (unsigned int)time(NULL) );	
	
	// Create an integer array of 100 elements
	int* intCache = new int[100];
	
	SplayTree< void * > cacheSplay;
	
	for(unsigned int i = 0; i < 100; i++){
		
		intCache[i] = i*2;
		cacheSplay.Insert( (intCache + i) );
		
	}
	
	printSplayRoot( cacheSplay );
	
	std::cout << "-------------" << std::endl;
	std::cout << cacheSplay << std::endl;
	
	for(unsigned int i = 0; i < 10; i++){
	
		// Get an int between 0 and 99
		int iter = rand() % 100;
		
		std::cout << "Seeking " << (intCache + iter) << ". ";
		std::cout << "Should find " << intCache[iter] << "... ";
		
		// Find the Splay
		cacheSplay.contains( (intCache + iter) );
		
		// Print the root
		printSplayRoot( cacheSplay );
		
		if( cacheSplay.returnRootVal() == (intCache + iter) ){
			
			std::cout << "... Test Passed!" << std::endl;
		}
		else{
			
			std::cout << "... Test Failed." << std::endl;
		}
	
	}
	
	return 0;
	
}