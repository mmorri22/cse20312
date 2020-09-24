#include <string>
#include <iostream>
#include "../include/DynArr.h"
#include "../include/LinearProbe.h"

template<class T>
int longConsec(DynArr<T>& theArr){
	
    /* The Hash Table */
    HashTable<T, int> countSort;
	
	// Insert the elements into the Hash 
    for(unsigned int iter = 0; iter < theArr.size(); iter++){
        countSort.insert({theArr[iter], 1});
    }

    int result = 0;

    for(unsigned int iter = 0; iter < theArr.size(); iter++){
        int count = 1;
        T num = theArr[iter];
		
		if( countSort.contains( num ) ){
			
			T down = (T)(num - 1);
			while (countSort.contains(down)){
				countSort.remove(down);
				down--;
				count++;
			}
			T up = (T)(num + 1);
			while(countSort.contains(up)){
				countSort.remove(up);
				up++;
				count++;
			}
			
			if (count > result){
				result = count;
			}
			countSort.remove(num);
		}
    }
    return result;
}


int main(){
    std::cout << "Test 1: <int>" << std::endl;
    DynArr<int> theVals;
    theVals.push_back(100);
    theVals.push_back(4);
    theVals.push_back(200);
    theVals.push_back(1);
    theVals.push_back(3);
    theVals.push_back(2);
    std::cout << theVals << std::endl;
    int result1 = longConsec(theVals);
    std::cout << "The length of the longest consecutive element is: " << result1 << std::endl;

    std::cout << std::endl << "Test 2: <char>" << std::endl;
    DynArr<char> theChars;
    theChars.push_back('e');
    theChars.push_back('A');
    theChars.push_back('b');
    theChars.push_back('c');
    theChars.push_back('a');
    theChars.push_back('B');
    theChars.push_back('d');
    std::cout << theChars << std::endl;
    int result2 = longConsec(theChars);
    std::cout << "The length of the longest consecutive element is: " << result2 << std::endl;


    std::cout << std::endl << "Test 3: <unsigned int>" << std::endl;
    DynArr<unsigned int> theUnsigned;
    theUnsigned.push_back(31);
    theUnsigned.push_back(7);
    theUnsigned.push_back(127);
    theUnsigned.push_back(30);
    theUnsigned.push_back(28);
    theUnsigned.push_back(29);
    std::cout << theUnsigned << std::endl;
    int result3 = longConsec(theUnsigned);
    std::cout << "The length of the longest consecutive element is: " << result3 << std::endl;

    std::cout << std::endl << "Test 4: <long unsigned int>" << std::endl;
    DynArr<long unsigned int> theLong;
    theLong.push_back(131);
    theLong.push_back(140);
    theLong.push_back(132);
    theLong.push_back(149);
    theLong.push_back(2);
    theLong.push_back(133);
    std::cout << theLong << std::endl;
    int result4 = longConsec(theLong);
    std::cout << "The length of the longest consecutive element is: " << result4 << std::endl;


    std::cout << std::endl << "Test 5: <long unsigned int>" << std::endl;
    DynArr<long unsigned int> theLong2;
	//36, 41, 56, 35, 37, 33, 34, 92, 42, 32

    theLong2.push_back(36);
    theLong2.push_back(41);
    theLong2.push_back(56);
    theLong2.push_back(35);
    theLong2.push_back(37);
    theLong2.push_back(33);
    theLong2.push_back(34);
    theLong2.push_back(92);
    theLong2.push_back(42);
    theLong2.push_back(32);
    std::cout << theLong2 << std::endl;
    int result5 = longConsec(theLong2);
    std::cout << "The length of the longest consecutive element is: " << result5 << std::endl;

    return 0;


}
