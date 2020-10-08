#include "../include/SorDLList.h"
#include "../include/MaxHeap.h"
#include "../include/DynArr.h"
#include <ctime>

#define COUT std::cout
#define ENDL std::endl

const long unsigned int MAXLISTS = 10;
const long unsigned int MAXVALS = 40;

DLList< int > SortKLists( DynArr< SorDLList< int > >& kSortedLists, long unsigned int numLists ){
	
	MaxHeap<int> theHeap;
	
	for( unsigned int iter = 0; iter < (unsigned int)numLists; iter++ ){
		
		while( !kSortedLists[iter].IsEmpty() ){
			
			theHeap.push( kSortedLists[iter].front() );
			
			kSortedLists[iter].pop_front();
		}
	}
	
	DLList< int > result;
	
	while( !theHeap.empty() ){
		
		result.push_front( theHeap.top() );
		
		theHeap.pop();
	}
	
	return result;
}

int main(){
	
	DynArr< SorDLList< int > > kSortedLists;
	
	/* Generate Random Numbers */
	srand( (unsigned int)time(0) );
	
	/* Create a number of lists between 1 and 10 */
	long unsigned int numLists = (rand() % MAXLISTS);
	
	for( long unsigned int iter = 0; iter < numLists; iter++ ){ 
	
		/* Create a temporary List */
		SorDLList< int > tempList;
		
		/* Put the temporary List into the kSortedLists */
		kSortedLists.push_back( tempList );
	}
	
	/* Get a random number of values between 0 and 40 */
	unsigned int numValues = (unsigned int)(rand() % MAXVALS);
	
	/* Do not push if the number of lists is 0 */
	if( numLists != 0 ){
		
		for(  unsigned int iter = 0; iter < numValues; iter++ ){
			
			/* Get a random list */
			unsigned int currList = (unsigned int)(rand() % numLists);
			
			/* Get a random integer */
			int value = (int)( rand() % 100 );
			
			/* Put the random integer into the randomly selected list */
			kSortedLists[ currList ].Insert( value );
		}
		
	}
	
	/* Print the generated lists to the user */
	COUT << "There are " << kSortedLists.size() << " lists to sort: " << ENDL;
	for( unsigned int iter = 0; iter < kSortedLists.size(); iter++ ){
		
		COUT << "List " << iter + 1 << ": " << kSortedLists[iter] << ENDL;
		
	}
	
	/* Sort the k lists */
	DLList<int> result = SortKLists( kSortedLists, numLists );
	
	COUT << ENDL << "Final Sorted List: " << result << ENDL;
	
}