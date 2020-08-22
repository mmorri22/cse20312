#include "../include/sol1.h"
#include <iostream>

int main(void){
	
	// Default constructor - Length 0
	COUT << "First Solution: " << ENDL;
	std::vector<int> stock;
	
	// Push back values 
	stock.push_back(7); 	stock.push_back(1);
	stock.push_back(5); 	stock.push_back(3);
	stock.push_back(6); 	stock.push_back(4);
	
	printArray(stock);
	
	
	// Default constructor - Length 0
	COUT << ENDL;
	COUT << "Second Solution: " << ENDL;
	std::vector<int> stock2;
	
	// Push back values 
	stock2.push_back(7); 	stock2.push_back(6);
	stock2.push_back(4); 	stock2.push_back(3);
	stock2.push_back(1); 
	
	printArray(stock2);
	
	return 0;
}