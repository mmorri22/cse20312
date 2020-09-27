#include "../include/SplayTree.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl

template<class T>
void insertSplay(SplayTree<T>& theTree, const T& value){
	
	std::cout << "Inserting " << value << " into the splay..." << std::endl;
	theTree.Insert(value);
	COUT << theTree << ENDL;
	COUT << "------------------------------" << ENDL;
}

template<class T>
void checkContains(SplayTree<T>& theTree, const T& value){
	
	std::cout << "Checking if " << value << " is in the tree..." << std::endl;
	std::cout << value << " is ";
	
	if(!theTree.contains(value)){

		std::cout << "not ";
	}		
	std::cout << "in the tree" << std::endl;

	COUT << theTree << ENDL;
	COUT << "------------------------------" << ENDL;
}

template<class T>
void deleteSplay(SplayTree<T>& theTree, const T& value){
	
	std::cout << "Deleting " << value << " from the splay..." << std::endl;
	theTree.remove( 10 );
	COUT << theTree << ENDL;
	COUT << "------------------------------" << ENDL;
	
}

int main(){
	
	SplayTree<int> theTree;
	
	insertSplay(theTree, 12);	insertSplay(theTree, 10);	insertSplay(theTree, 8);
	insertSplay(theTree, 13);	insertSplay(theTree, 11);	insertSplay(theTree, 14);
	insertSplay(theTree, 16);	insertSplay(theTree, 15);	insertSplay(theTree, 17);
	insertSplay(theTree, 7);	insertSplay(theTree, 9);
	
	checkContains(theTree,10);	checkContains(theTree,18);	checkContains(theTree,15);	
	checkContains(theTree,6);
	
	deleteSplay(theTree, 10);

	
	//SplayTree<std::string> NDSong;
	//NDSong.Insert("Send");
	//NDSong.Insert("A");
	//NDSong.Insert("Volley");
	//NDSong.Insert("Cheer");
	//NDSong.Insert("On");
	//NDSong.Insert("High");
	
	//COUT << NDSong << ENDL;
	
	return 0;
}