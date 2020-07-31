#ifndef TRIENODE_H
#define TRIENODE_H

#include "SorDynArr.h"

class TrieNode{

private:

	char trieLetter;
	SorDynArr< TrieNode > childNodes;

public:

	// Default constructor
	TrieNode() : trieLetter(), childNodes(0) {}
	
	// Constructor with char input
	TrieNode(char charIn) : trieLetter(charIn), childNodes(0) {}
	
	// Add a child character
	void addChild( char childChar ){

		TrieNode temp(childChar);

		// Check if the letter already exists
		for(unsigned int iter = 0; iter < childNodes.length(); iter++){

			if( childNodes[iter].getLetter() == childChar ){

				// Do not add duplicate
				return;

			}
			
			if( childNodes[iter].getLetter() > childChar ){
				// Greater than the currentChar
				// Not in Sorted 
				break;
			}
		}
		
		// Insert the node in the Sorted Array
		childNodes.Insert(temp);
	}

	
	// Get the Child Pointer
	TrieNode* getChildPtr( char childChar ){
		
		for(unsigned int iter = 0; iter < childNodes.length(); iter++){
			
			if( childNodes[iter].getLetter() == childChar ){
				
				return &childNodes[iter];
			}
			
		}
		
		// If it gets here, there was no child 
		return NULL;
		
	}
	
	
	TrieNode* getChildPtrOrder( unsigned int order ){
		
		return &childNodes[ order ];
		
	}
	
	// Get Letter
	char getLetter() const{
		
		return trieLetter;
		
	}
	
	unsigned int numChildren() const{
		
		return childNodes.length();
		
	}
	
	// Operators
	bool operator<( const TrieNode& rhs ) const{
		
		return trieLetter < rhs.trieLetter;
	}
	
	bool operator<=( const TrieNode& rhs ) const{
		
		return trieLetter <= rhs.trieLetter;
	}
	
	bool operator>( const TrieNode& rhs ) const{
		
		return trieLetter > rhs.trieLetter;
	}
	
	bool operator>=( const TrieNode& rhs ) const{
		
		return trieLetter >= rhs.trieLetter;
	}
	
	bool operator==( const TrieNode& rhs ){
		
		return trieLetter == rhs.trieLetter;
	}
	
	friend std::ostream& operator<<( std::ostream& output, const TrieNode& TN){
		
		output << TN.trieLetter << " ";
		
		return output;
	}

};

#endif