#include "../include/PriorityQueue.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main( )
{
    PriorityQueue<int> thePQ;

    COUT << "Begin test.\nInserting: ";
    for( int i = 45; i != 0; i = ( i + 45 ) % 500 ){
		
		COUT << i << " ";
		
		thePQ.push( i );
	}
	
	COUT << ENDL << ENDL;

	COUT << "Removing : ";
    while( !thePQ.empty( ) )
    {
		COUT << thePQ.front( ) << " ";
		thePQ.pop( );
    }

    COUT << "\nSuccessfully completed test!" << ENDL;

    return 0;
}