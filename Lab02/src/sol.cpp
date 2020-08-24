#include "../include/sol.h"

#include <iostream>

int main(void){
	
	// Default constructor - Length 0
	COUT << "First Solution: " << ENDL;
	std::vector<int> stock;
	
	// Push back values 
	stock.push_back(7);
	stock.push_back(1);
	stock.push_back(5);
	stock.push_back(3);
	stock.push_back(6);
	stock.push_back(4);
	
	printArray(stock);
	
	findSolution(stock);
	
	// Default constructor - Length 0
	COUT << ENDL << "Second Solution: " << ENDL;
	std::vector<int> stock2;
	
	// Push back values 
	stock2.push_back(7);
	stock2.push_back(1);
	stock2.push_back(5);
	stock2.push_back(3);
	stock2.push_back(6);
	stock2.push_back(4);
	stock2.push_back(0);
	stock2.push_back(4);
	
	printArray(stock2);
	
	findSolution(stock2);
	
	
	// Default constructor - Length 0
	COUT << ENDL << "Third Solution: " << ENDL;
	std::vector<int> stock3;
	
	// Push back values 
	stock3.push_back(7);
	stock3.push_back(1);
	stock3.push_back(5);
	stock3.push_back(3);
	stock3.push_back(6);
	stock3.push_back(4);
	stock3.push_back(0);
	stock3.push_back(8);
	
	printArray(stock3);
	
	findSolution(stock3);
	
	
	// Default constructor - Length 0
	COUT << ENDL;
	COUT << "Fourth Solution: " << ENDL;
	std::vector<int> stock4;
	
	// Push back values 
	stock4.push_back(7);
	stock4.push_back(6);
	stock4.push_back(4);
	stock4.push_back(3);
	stock4.push_back(1);
	
	printArray(stock4);
	
	findSolution(stock4);
	
	return 0;
}