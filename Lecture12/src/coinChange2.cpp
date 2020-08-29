#include <iostream>
#include <sstream>

#include "../include/LinearProbe.h"

int minimum( int one, int five, int ten, int twenty_five, int fifty ){
	
	int result = ( fifty < twenty_five ) ? fifty : twenty_five;
	
	result = ( ten < result ) ? ten : result;
	
	result = ( five < result ) ? five : result;
	
	result = ( one < result ) ? one : result;
	
	return result;
	
}

int coins(int n, HashTable<int, int>& coinVals){

	/* If the Hash contains the value, just return */
	if(coinVals.contains(n))
		return coinVals[n];
	
	/* Base Cases for Steps */
	if(n <= 0 ){
		return 2147483647;
	}
	else if(n == 1 || n == 5 || n == 10 || n == 25 || n == 50){
		
		coinVals.insert( {n, 1} );
		return 1;
		
	}
	
	/* Insert the value into the Hash Table */
	int minCoins = minimum( coins(n-1, coinVals), coins(n-5, coinVals), 
		coins(n-10, coinVals), coins(n-25, coinVals), coins(n-50, coinVals) );
	
	coinVals.insert( {n, 1 + minCoins} );
	
	return coinVals[n];
	
}

int main(int argc, char**argv){
	
	if(argc != 2){
		std::cerr << "Incorrect Number of inputs" << std::endl;
		exit(-1);
	}
	
	// stringstream used for the conversion initialized with the contents of argv[1]
	int stepNum;
	std::stringstream convert(argv[1]);

	//give the value to stepNum using the characters in the string
	if ( !(convert >> stepNum) ){
		std::cerr << "Not a valid input" << std::endl;
		exit(-1);
	}
	
	/* Create the Memoization Hash Table */
	HashTable<int, int> coinVals;
	
	/* Call the recursive function */
	int result = coins( stepNum, coinVals );
	
	if( result == 2147483647 ){
		
		std::cout << -1 << std::endl;
		
	}
	else{
		
		std::cout << result << std::endl;
	}
	
	return 0;
	
}
