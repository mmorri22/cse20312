#include "../include/BTree.h"
#include <iostream>
#include <string>

struct Data
{
    int data;
    int key;
	
	Data(){}

    Data(int data, int key) : data(data), key(key){}

    bool operator>(const Data& rhs) const{
        if (key > rhs.key)
            return true;
        else
            return false;
    }

    bool operator<(const Data& rhs) const{
        if (key < rhs.key)
            return true;
        else
            return false;
    }

    bool operator==(const Data& rhs) const{
        if (key == rhs.key)
            return true;
        else
            return false;
    }
/*
    Data* operator=(const Data& rhs) {
        key = rhs.key;
        data = rhs.data;
		
		return this;
    }
*/
    friend std::ostream& operator<<(std::ostream& outStream, const Data& printData);

};

std::ostream& operator<<(std::ostream& outStream, const Data& printData) {
    outStream << printData.data << ", " << printData.key;
    return outStream;
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* This is the main driver function for the program
********************************************/
int main(int argc, char** argv){

    // Initial test code
    BTree<Data> database(3);

    Data node1(1,2);
    Data node2(3,4);
    Data node3(5,6);

    database.insert(node1);
    database.insert(node2);
    database.insert(node3);

    database.insert(node1);
    database.insert(node2);
    database.insert(node3);

    std::cout << "Traversal of tree constructed is\n";
    database.traverse();
    std::cout << std::endl;
	
    return 0;
}
