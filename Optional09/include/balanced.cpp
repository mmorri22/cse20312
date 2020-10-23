#include "balanced.h"

// define function for reading code from file
void getCode(IFSTREAM& CodeFile, VECTOR< STRING >& codeVector){

	// create temporary string
	STRING tempString;

	// Get the line from the file
	while (std::getline(CodeFile, tempString, '\n')){

		// Push it back onto the vector
		codeVector.push_back(tempString);
	}

	CodeFile.close();
}

bool checkCode(VECTOR< STRING >& codeVector){

	// assign string to temporary variable
	STACK<char> tempStack;

	// loop through each string in vector
	for (unsigned int i = 0; i < codeVector.size(); i++){

		// loop through every character in the string
		for (unsigned int j = 0; j < codeVector.at(i).size(); j++){

			switch( codeVector.at(i).at(j) ) {
				
				// Left cases - Push onto the Stack
				case '{' :
					tempStack.push('{');
					break;
				case '(' :
					tempStack.push('(');
					break;
				case '[' :
					tempStack.push('[');
					break;
				
				// Right cases - Either pop or fail
				case '}':
					if( tempStack.top() == '{' ){
						tempStack.pop();
					}
					else{
						return false;
					}
					break;
				case ')':
					if( tempStack.top() == '(' ){
						tempStack.pop();
					}
					else{
						return false;
					}
					break;
				case ']':
					if( tempStack.top() == '[' ){
						tempStack.pop();
					}
					else{
						return false;
					}
					break;
				
				default:
					// Do nothing
					break;

			}	
		}	
	}
	
	return tempStack.size() == 0;
}
