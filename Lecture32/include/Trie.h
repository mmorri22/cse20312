#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"

class Trie{
	
	private:
	
		void addString( TrieNode* theNode, const std::string& word, unsigned int value ){
		
			if( value < word.size() ){
				
				theNode->addChild( word[value] );
				
				TrieNode* nextLevel = theNode->getChildPtr( word[value] );
				
				addString( nextLevel, word, value + 1);
			}
			
			else if( value == word.size() ){
				
				theNode->addChild( '*' );
				
			}
		
		}
		
		
		void printTriePreOrder( TrieNode* theNode, unsigned int level ){
			
			if( theNode == NULL ){
				
				return;
				
			}
			
			// Root Node 
			if( theNode->getLetter() == 0 ){
				
				std::cout << "root: " << level << std::endl;
				
			}
			
			else{
				
				std::cout << theNode->getLetter() << " " << level << std::endl;
				
			}
			
			if( theNode->getLetter() == '*' ){
				
				return;
				
			}
			
			// If we get here, there are children 
			for(unsigned int iter = 0; iter < theNode->numChildren(); iter++){
			
				printTriePreOrder(theNode->getChildPtrOrder(iter), level + 1);
				
			}
			
		}
		
		
		bool contains( TrieNode* theNode, const std::string& word, unsigned int value ) const {
			
			// Check if we are at the end of the string 
			if( value == word.size() ){
				
				// If theNode's first child is '*', then we found the word!
				if( theNode->getChildPtrOrder( 0 )->getLetter() == '*' ){
					
					return true;
					
				}
				else{
					// A valid word is a subset of word, but word is not in the Trie 
					return false;
				}
			}
			
			// Otherwise, we can still recurse 
			unsigned int iter = 0;
			while( iter < theNode->numChildren() ){
				
				if( theNode->getChildPtrOrder(iter)->getLetter() == word[ value ] )
					break;
				
				iter++;
			}
			
			if( iter < theNode->numChildren() ){
								
				return contains( theNode->getChildPtrOrder(iter), word, value + 1 );
				
			}
			
			return false;
			
			
		}

	
		TrieNode* root;
	
	public:
	
		Trie() : root( new TrieNode() ) {}
		
		void addString( const std::string& word ){
			
			addString( root, word, 0 );
			
		}
		
		
		void printTriePreOrder( ){
			
			printTriePreOrder(root, 1);
			
		}
		
		
		bool contains( const std::string& word ) const{
			
			unsigned int iter = 0;
			
			while( iter < root->numChildren() ){
				
				if( root->getChildPtrOrder(iter)->getLetter() == word[0] )
					break;
				
				iter++;
			}
			
			if( iter < root->numChildren() ){
				
				return contains( root->getChildPtrOrder(iter), word, 1 );
				
			}
			
			return false;
		}
	
};

#endif