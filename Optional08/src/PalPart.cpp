/**********************************************
* File: PalPart.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the solution and main driver
* for find the partitions of a string which are
* a palindrome 
**********************************************/

#include "../include/PalPart.h"


/********************************************
* Function Name  : allPalPartRun
* Pre-conditions : none
* Post-conditions: none
* 
* Tests all the cases for the Palindrom Partition 
********************************************/
void testPalinPartRun(){
	
    allPalPartitions(""); 
	
    allPalPartitions("a"); 
	
    allPalPartitions("abc");

    allPalPartitions("abcdcbefgfeh");

    allPalPartitions("abcdcbbcdcba");
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main( ){

	//testPalRun();  		// Successfully tested
	//testPalPartRun();	// Successfully tested
	
	testPalinPartRun();
	
	return 0;
}    



