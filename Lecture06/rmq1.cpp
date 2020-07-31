#include <iostream>

#define COUT std::cout
#define ENDL std::endl 
  
// Structure to represent a query range 
struct RMQuery 
{ 
    unsigned int left, right; 
	
	RMQuery(unsigned int leftIn, unsigned int rightIn) : left(leftIn), right(rightIn) {}
}; 
  
// Fills lookup array lookup[n][n] for all possible values of 
// query ranges 
template< class T >
unsigned int** preprocess(T arr[], long unsigned int n) 
{ 

	// Allocate the array for all the values 
	unsigned int** lookup = (unsigned int **)malloc( n * sizeof(unsigned int *) );
	
	// Allocate the array for each element
	for( long unsigned int iter = 0; iter < n; iter++ ){
		
		lookup[iter] = (unsigned int *)malloc( n * sizeof(unsigned int) );
	}

    // Initialize lookup[][] for the intervals with length 1 
    for (int i = 0; i < (int)n; i++) 
        lookup[i][i] = i; 
  
    // Fill rest of the entries in bottom up manner 
    for (int i=0; i< (int)n; i++) 
    { 
        for (int j = i+1; j< (int)n; j++) 
  
           // To find minimum of [0,4], we compare minimum of 
           // arr[lookup[0][3]] with arr[4]. 
           if (arr[lookup[i][j - 1]] < arr[j]){ 
              lookup[i][j] = lookup[i][j - 1]; 
		   }
           else{
              lookup[i][j] = j;
		   }			  
    } 
	
	for(int i=0; i< (int)n; i++) 
    { 
		for(long unsigned int j=0; j<n; j++) 
		{ 
			std::cout << lookup[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return lookup;
} 
  
// Prints minimum of given m query ranges in arr[0..n-1] 
template< class T >
void RMQ( T arr[], unsigned int** lookup, RMQuery theQuery ) 
{ 
  
	// Left and right boundaries of current range 
	int left = q.left, right = q.right; 

	// Print sum of current query range 
	COUT << "Minimum of [" << left << ", " << right << "] is ";  
	COUT << arr[ lookup[ theQuery.left ][ theQuery.right ] ] << ENDL; 
		 
} 

void test1(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(0, 3);	
	RMQuery q2(1, 4);
	RMQuery q3(4, 7);
	RMQuery q4(6, 7);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}


void test2(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93, 18, 46, 99, 5, 22, 17, 85, 42, 7}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(6, 7);	
	RMQuery q2(1, 4);
	RMQuery q3(4, 7);
	RMQuery q4(1, 15);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}


void test3(){
	
	// Initialize the array length 
    char rmqArray[] = {'N', 'o', 't', 'r', 'e', 'D', 'a', 'm', 'e'}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(0, 1);	
	RMQuery q2(0, 4);
	RMQuery q3(1, 4);
	RMQuery q4(4, 7);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}
  
// Driver program 
int main() 
{ 
	// Initial 8 integer from slides
	test1();
	
	// Next 16 integer array from slides 
	test2();
	
	// Character test with letters from Notre Dame
	test3();
} 
