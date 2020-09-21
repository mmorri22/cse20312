#include <iostream>
#include <cstdlib>
#include "../include/Tower.h"

void move(Tower& source, Tower& destination, int& numMoves){
	
	numMoves++;
	
	std::cout << "Move " << numMoves << ": ";
	std::cout << "Weight #" << source.theStack.top();
	std::cout << " from " << source.getTowerNum() << " to ";
	std::cout << destination.getTowerNum() << std::endl;
	
	destination.theStack.push( source.theStack.top() );
	
	source.theStack.pop();
	
}


void hanoi( int n, Tower& source, Tower& destination,
	Tower& auxillary, int& numMoves){
		
	if( n > 0 ){
		
		hanoi( n-1, source, auxillary, destination, numMoves );
		
		move( source, destination, numMoves );
		
		hanoi( n-1, auxillary, destination, source, numMoves );
		
	}
		
		
}


int main( int argc, char** argv ){
	
	if( argc != 2 ){
		
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
		
	}
	
	int STACK_SIZE = atoi( argv[1] );
	
	int numMoves = 0;
	
	Tower tower1(1);
	Tower tower2(2);
	Tower tower3(3);
	
	for( int i = STACK_SIZE; i > 0; i--){
		
		tower1.theStack.push(i);
		
	}
	
	hanoi( STACK_SIZE, tower1, tower2, tower3, numMoves );
	
	return 0;
}




