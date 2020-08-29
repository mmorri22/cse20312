#include "../include/DynArr.h"
#include <iostream>
#include <vector>

#define COUT std::cout
#define ENDL std::endl

void printArray( DynArr<int>& theArray ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray[iter];
		
		if( iter < theArray.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]" << ENDL;
	
}


int maxSubArrayProdDyn( DynArr<int>& array ) 
{ 
    
    int globalMaximum = 1;  /* The Global Maximum */ 
    bool positiveFlag = false;   /* Flag for if we have a positive result */
    
    /* Maximum positive product ending at the current position */
    int maxPosCurrProduct = 1; 
  
    /* Minimum negative product ending at the current position */
    int minNegCurrProduct = 1; 
    
    /* Iterate through the array */
    for (unsigned int i = 0; i < array.size(); i++) { 
        
        if (array[i] > 0) { 
            
            /* Multiple the postive value on maxPosCurrProduct */
            maxPosCurrProduct *= array[i]; 
            
            /* Only update the negative value is the value is not 1 */
            minNegCurrProduct = minNegCurrProduct * array[i];
            minNegCurrProduct = (minNegCurrProduct < 1) ? minNegCurrProduct : 1;
            
            positiveFlag = true; 
        } 
  
        /* If the value is 0, reset both locals to 1 */
        else if (array[i] == 0) { 
            maxPosCurrProduct = 1; 
            minNegCurrProduct = 1; 
        } 
  
         
       /* Value is negative */
        else { 
            int temp = maxPosCurrProduct; 
            maxPosCurrProduct = (minNegCurrProduct * array[i] > 1) ? minNegCurrProduct * array[i] : 1;
            minNegCurrProduct = temp * array[i]; 
        } 
  
        /* If the local maximum is greater than global, then update */
        globalMaximum = (globalMaximum < maxPosCurrProduct) ? maxPosCurrProduct : globalMaximum;
        
    } 
    
    /* If not a positiveFlag and globalMaximum was never updated */
    if (!positiveFlag && globalMaximum == 1){
        return 0; 
    }
    
    return globalMaximum; 
} 


int main(){
	
	// Create first array
	DynArr<int> array1;

	array1.push_back( -2 );		array1.push_back( 1 );
	array1.push_back( -3 );		array1.push_back( 4 );
	array1.push_back( -1 );		array1.push_back( 2 );
	array1.push_back( 1 );		array1.push_back( -5 );	
	array1.push_back( 4 );		array1.push_back( 1 );		
	
	printArray( array1 );
	COUT << "Max Size = " << maxSubArrayProdDyn(array1) << ENDL;
	
	array1.push_back( -10 );	
	COUT << ENDL;
	printArray( array1 );
	COUT << "Max Size = " << maxSubArrayProdDyn(array1) << ENDL;	
	

	// 10, 35, -2, 18, -10, -5, 100

	DynArr<int> array2;
	array2.push_back( 10 );		array2.push_back( 32 );
	array2.push_back( -2 );		array2.push_back( 18 );
	array2.push_back( -10 );	array2.push_back( -5 );
	array2.push_back( 100 );	
	
	COUT << ENDL;
	printArray( array2 );
	COUT << "Max Size = " << maxSubArrayProdDyn(array2) << ENDL << ENDL;
	
	// Replace 18 with 0
	array2[ 3 ] = 0;
	COUT << ENDL;
	printArray( array2 );
	COUT << "Max Size = " << maxSubArrayProdDyn(array2) << ENDL << ENDL;
	
	
	DynArr<int> array3; 
	array3.push_back( -1 );		array3.push_back( 10 );
	array3.push_back( 15 );		array3.push_back( 0 );
	array3.push_back( 5 );		array3.push_back( 3 );		
	
	COUT << ENDL;
	printArray( array3 );
	COUT << "Max Size = " << maxSubArrayProdDyn(array3) << ENDL << ENDL;
	
	return 0;
}