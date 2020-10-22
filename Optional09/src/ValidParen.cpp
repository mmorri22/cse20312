#include "../include/balanced.h"

// proceed through main function
int main(int argc, char** argv){

  // check if number of arguments passed is correct
  if (argc != 2){
    std::cerr << "Error: Input format should be ./HW06 [File Name]" << std::endl;
    exit(-1);
  }

  // open file
  IFSTREAM CodeFile;
  CodeFile.open(argv[1]);

  // check if file exists
  if ( !CodeFile.good() ){
    std::cerr << "Error: File not found" << std::endl;
    exit(-1);
  }

  else {

    // create vector of strings to store each file line
    VECTOR <STRING> codeVector;

    // call code reading function
    getCode(CodeFile, codeVector);

    // call code checking function
    if (checkCode(codeVector)){
      std::cout << "The code in " << argv[1] << " is valid code"<< std::endl;
    }
    else {
      std::cout << "The code in " << argv[1] << " is invalid code"<< std::endl;
    }
  }

  return 0;

}
