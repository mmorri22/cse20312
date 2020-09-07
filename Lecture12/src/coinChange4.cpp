#include <iostream>
#include <sstream>

#include "../include/LinearProbe.h"

int coins(int n, HashTable<int, int>& coinVals){

	/* If the Hash contains the value, just return */
	if(coinVals.contains(n))
		return coinVals[n];
	
	/* Base Cases for Steps */
	if(n <= 0 ){
		return -1;
	}
	else if(n == 1 || n == 5 || n == 10 || n == 25 || n == 50){
		
		coinVals.insert( {n, 1} );
		return 1;
		
	}
	
	/* Find the number of 50 cent pieces */
	int minFifty = ( n > 50 ) ? n / 50 : 0 ;
	
	/* Find the remaining cents after the 50 cent pieces */
	if( minFifty != 0 ){
		
		n = n % 50;
		
	}
	
	/* If n == 0, 50 cent pieces perfectly make up the coinage */
	if ( n == 0 ){
		
		coinVals.insert( {n, minFifty} );
		
		return minFifty;
	}
	
	/* Now we recursively call with 49 or fewer cents */
	int minCoins = coins( n - 25 , coinVals);
	
	if( minCoins == -1 ){
		minCoins = coins(n-10, coinVals);	
	}
	
	if( minCoins == -1 ){
		minCoins = coins(n-5, coinVals);
	}
	
	if( minCoins == -1 ){
		minCoins = coins(n-1, coinVals);
	}
	
	/* Either return -1 or numCoins + 1 */
	if( minCoins == -1 && minFifty == 0 ){
		coinVals.insert( {n, minCoins} );
	}
	else{
		coinVals.insert( {n, 1 + minCoins + minFifty} );	
	}
	
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
	
	if( result == -1 ){
		
		std::cout << -1 << std::endl;
		
	}
	else{
		
		std::cout << result << std::endl;
	}
	
	return 0;
	
}
