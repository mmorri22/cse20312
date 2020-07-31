#include "../include/DLList.h"


/********************************************
* Function Name  : getAndCheckInput
* Pre-conditions : char* argv
* Post-conditions: int
* 
* checks if the input is a valid integer 
********************************************/
int getAndCheckInput(char* argv){
	
	int iter;
	for(iter = 0; argv[iter] != 0; ++iter){
		
		/* First character can be an number or */
		if(iter == 0 && (argv[iter] < 48 || argv[iter] > 57) && argv[iter] != 45){
			std::cerr <<  "Not a valid input: " << argv << " " << argv[iter] << std::endl;
			exit(-1);
			
		}
		else if( iter > 0 && (argv[iter] < 48 || argv[iter] > 57) ){
			
			std::cerr <<  "Not a valid input: " << argv << " " << argv[iter] << std::endl;
			exit(-1);
		}
	}
	
	
	return atoi(argv);
}

int main(int argc, char** argv){
	
	
	/* Initialize Number of Inputs to Linked List */
	int listLen = argc - 1, iter;
	
	/* Call default constructor for Linked List */
	DLList<int> theList;
	
	/* Start at the first int, and go until the end of the command line */
	for(iter = 1; iter <= listLen; ++iter){
		
		int tempInt = getAndCheckInput(argv[iter]); // atoi(argv[iter]);
		theList.Insert(tempInt);	
		
	}
	
	/* Print the initial list */
	std::cout << "theList before: " << theList << std::endl;

	/* Remove the duplicates */
	theList.deleteDuplicates();
	
	/* Print the final list */
	std::cout << "theList after : " << theList << std::endl;	
	
}