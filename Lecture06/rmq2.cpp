#include <iostream>
#include <cmath> // For log2 in RMQ 

#define COUT std::cout
#define ENDL std::endl 

// Structure to represent a query range 
struct RMQuery 
{ 
    unsigned int left, right; 
	
	RMQuery(unsigned int leftIn, unsigned int rightIn) : left(leftIn), right(rightIn) {}
}; 
  
// Fills lookup array lookup[][] in bottom up manner. 
template< class T >
unsigned int** preprocess(T arr[], long unsigned int n) 
{ 

	// Allocate the array for all the values 
	unsigned int** lookup = (unsigned int **)malloc( n * sizeof(unsigned int *) );
	
	// Allocate the array for each element
	for( long unsigned int iter = 0; iter < n; iter++ ){
		
		lookup[iter] = (unsigned int *)malloc( n * sizeof(unsigned int) );
	}

    // Initialize M for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = i; 
  
    // Compute values from smaller to bigger intervals 
    for (int j=1; (1<<j)<=n; j++) 
    { 
        // Compute minimum value for all intervals with size 2^j 
        for (int i=0; (i+(1<<j)-1) < n; i++) 
        {  
            // For arr[2][10], we compare arr[lookup[0][3]] and 
            // arr[lookup[3][3]] 
            if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]]) 
                lookup[i][j] = lookup[i][j-1]; 
            else
                lookup[i][j] = lookup[i + (1 << (j-1))][j-1];       
        } 
    } 
	
	// Print the preprocessed results to the user
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
  
    // For [2,10], j = 3 
    unsigned int j = (unsigned int)log2( theQuery.right - theQuery.left + 1 ); 
  
    // For [2,10], we compare arr[lookup[0][3]] and 
    // arr[lookup[3][3]],  
	unsigned int lookupLeft = lookup[theQuery.left][j];
	unsigned int lookupRight = lookup[theQuery.right - (1<<j) + 1][j];
	
	T solution;
	
    if ( arr[lookupLeft] <= arr[lookupRight] ){
        solution = arr[lookupLeft]; 
	}
  
	else{ 
		solution = arr[lookupRight]; 
	}		

	// Print sum of current query range 
	COUT << "Minimum of [" << theQuery.left << ", " << theQuery.right << "] is ";  
	COUT << solution << ENDL; 
		 
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

