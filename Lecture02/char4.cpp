/**********************************************
* File: char4.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a char pointer and memory, sets all the characters
* to Hello, World, and then prints their addresses and values
*
* Lecture 02 - Slide 37
**********************************************/

#include <iostream>
#include <cstdlib>

int main(void){
	
	long unsigned int numCharacters = 13;
	
	char* hello = (char *)malloc( numCharacters * sizeof(char) );
	char* reference = hello;
	
	*(hello + 0) = 'H';
	*(hello + 1) = 'e';
	*(hello + 2) = 'l';
	*(hello + 3) = 'l';
	*(hello + 4) = 'o';
	*(hello + 5) = ',';
	*(hello + 6) = ' ';
	*(hello + 7) = 'W';
	*(hello + 8) = 'o';
	*(hello + 9) = 'r';
	*(hello + 10) = 'l';
	*(hello + 11) = 'd';
	*(hello + 12) = '\n';
	
	for(long unsigned int iter = 0; iter < numCharacters; iter++){
		
		std::cout << (void *)reference << " " << *(reference) << std::endl;
		reference = reference + 1;
	}
	
	free( hello );

	return 0;
}
