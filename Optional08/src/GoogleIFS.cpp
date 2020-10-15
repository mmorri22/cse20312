/**********************************************
* File: GoogleIFS.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a solution to the Google License Interview question 
* using no data structure to store the dictionary words, but
* reading in from the file for every call 
* 
* Compilation command: g++ -g -std=c++11 -Wpedantic GoogleMulIFS.cpp -o GoogleMulIFS
* Run: ./GoogleMulIFS [DictionaryFile]
* Example: ./GoogleIFS words.txt
**********************************************/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <iterator>

/********************************************
* Function Name  : getAndCheckFile
* Pre-conditions : std::ifstream& fileStream, std::string fileName
* Post-conditions: none
* 
* Verifies a valid file and returns an input stream
********************************************/
void getAndCheckFile(std::ifstream& fileStream, std::string fileName){
	
	fileStream.open(fileName);
	
	if(!fileStream.is_open()){
		
		std::cout << "The file " << fileName << " does not exist. Exiting Program..." << std::endl;
		exit(-1);
		
	}
	
}

/********************************************
* Function Name  : HashLicense
* Pre-conditions : std::unordered_map< char, int >& HashPlate, char* plate
* Post-conditions: none
* 
* Stores the value of the hash values in the HashMap  
********************************************/
void HashLicense(std::unordered_map< char, int >& HashPlate, char* plate){
	
	for(int i = 0; plate[i] != '\0'; i++){
		
		// Assume ASCII and all uppercase letters -> 65-90
		if((int)plate[i] >= 65 && (int)plate[i] <= 90){
		
			if(HashPlate.count(plate[i]) == 0){
				
				// Put the word in, and set the count to 1
				HashPlate.insert( {plate[i], 1} );
			}
			else{
				// Increment the count 
				HashPlate[plate[i]]++;
			}
		}
	}
}

/********************************************
* Function Name  : HashWord
* Pre-conditions : std::unordered_map< char, int >& HashPlate, std::string currWord, std::string& finalWord
* Post-conditions: none
*  
********************************************/
void HashWord(std::unordered_map< char, int >& HashPlate, std::string currWord, std::string& finalWord){
	
	// Create a temporary Hash for the current work 
	std::unordered_map< char, int > HashWord;
	
	for(long unsigned int iter = 0; iter < currWord.length(); iter++){
		
		// words.txt contains all uppercase, but some words may contain numbers 
		if((int)currWord[iter] >= 65 && (int)currWord[iter] <= 90){
			
			if(HashWord.count(currWord[iter]) == 0){
				
				// Put the word in, and set the count to 1
				HashWord.insert( {currWord[iter], 1} );
			}
			else{
				// Increment the count 
				HashWord[currWord[iter]]++;
			} 
			
		}
	}
	
	// Now, go through each character in HashPlate 
	for(std::unordered_map<char, int>::iterator iter = HashPlate.begin(); iter != HashPlate.end(); iter++){
		// if the value in the HashWord is less than HashPlate, 
		// then the # of that character in the word is less than the license plate
		// which means it cannot be a valid choice. Return.
		if(HashWord[iter->first] < iter->second){
			return;
		}
	}
	
	// Went through all the characters in HashPlate and they were found in 
	// the current word. Therefore, currWord is the current solution 
	finalWord = currWord;
	
}

void checkPlate(char* fileName, char* plateStr){

	// Get the inputstream
	std::ifstream dictionaryFile;

	// Create the Dictionary File
	getAndCheckFile(dictionaryFile, fileName);

	// Get and Hash License Plate
	std::unordered_map< char, int > HashPlate;
	
	// Hash the values of the characters in the license plate  
	HashLicense(HashPlate, plateStr);

	// Set the string where the final word (solution) will be stored
	std::string finalWord;
	
	// Iterate through each word in the dictionary 
	std::string currWord;
	while (dictionaryFile >> currWord)
	{	
		// Check the word, and update final word if it qualifies
		// Do not hash currWord if final Word is the same length - Save run time 
		// Must also account for if no word is found yet (finalWord.length() > 0)
		if(currWord.length() < finalWord.length() || finalWord.length() == 0)
			HashWord(HashPlate, currWord, finalWord);
	}
	
	// Print the result to the user 
	std::cout << "Shortest Word in Dictionary with characters in " 
		<< plateStr << " is " << finalWord << std::endl;
		
	// Close the ifstream
	dictionaryFile.close();

}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* Main driver function for the program  
********************************************/
int main(int argc, char** argv){
	
	// Get the inputstream
	std::ifstream dictionaryFile;
	if(argc != 2){
		std::cout << "Number of inputs are wrong" << std::endl;
		std::cout << "./GoogleMulIFS [DictionaryFile]" << std::endl;
		exit(-1);
	}

	// In C++11, conversion from char* to string is depricated. Must do it here
	// Without (char*), it will compile and run. -Wpedantic will throw a warning
	checkPlate(argv[1], (char*)"RCT100SA");
	checkPlate(argv[1], (char*)"RT123SO");
	checkPlate(argv[1], (char*)"AQ10S0K");
	checkPlate(argv[1], (char*)"TNT055RB");
	checkPlate(argv[1], (char*)"LET10EE0");
	checkPlate(argv[1], (char*)"AB1C1D1");
	checkPlate(argv[1], (char*)"AEI1O2U3");
	checkPlate(argv[1], (char*)"OTR1N2E3");
	checkPlate(argv[1], (char*)"AM1E2D3");
	checkPlate(argv[1], (char*)"SHR5I3I3");

	return 0;

}

