#include "../include/Student.h"
#include "../include/BTree.h"

#include <cstdlib>
#include <fstream>
#include <sstream>

int main(int argc, char** argv){
	
	if( argc != 2 ){
		
		std::cout << "Incorrect Number of Inputs" << std::endl;
		exit(-1);
		
	}
	
	BTree< Student > stuBTree(4);
	
	std::ifstream dbIn(argv[1]);
	
	if(!dbIn){
		
		std::cout << "Invalid File: " << argv[1] << std::endl;
		exit(-1);		
	}
	
	while(!dbIn.eof()){
		
		// Get a line from dbIn and then create a stringstream
		std::string inLine;
		std::getline(dbIn, inLine);
		std::stringstream lineSS(inLine); 
		
		// First, get the ID
		std::string token;
		std::getline(lineSS, token, ',');
		unsigned int ID = atoi( token.c_str() );
		
		// get the First Name 
		std::string first;
		std::getline(lineSS, first, ',');
		
		// get the Last Name 
		std::string last;
		std::getline(lineSS, last, ',');

		// get the Last Name 
		std::string email;
		std::getline(lineSS, email, ',');
		
		// get the Last Name 
		std::string stuMajor;
		std::getline(lineSS, stuMajor, ',');
		
		// Create temp Student 
		Student tempStu(ID, first, last, email, stuMajor);
		
		// Insert the node into the B-Tree
		stuBTree.insert( tempStu );
		
	}
	
	Student seekVal;
	seekVal.setID(86);
	stuBTree.printFoundNodes( seekVal );
	std::cout << "-------------" << std::endl;
	seekVal.setID(10);
	stuBTree.printFoundNodes( seekVal );

	dbIn.close();
	
	return 0;
}