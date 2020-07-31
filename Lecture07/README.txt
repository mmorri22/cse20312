These code segments follow the order of Lecture 06 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - NO COMMAND

Files: classes/DynArr1.h

Slides: 5-6

Shows the Dynamic Array constructor, with DynArr(const int sizeIn = 0) to show you can make the default constructor and overloaded constructor in C++ using an overloaded precondition

-------------------------------------------------

Command 2 - NO COMMAND

Files: classes/DynArr2.h

Slides: 7

Modifies DynArr1.h by showing the destructor and how you can remove the allocated memory from the heap using delete [] data

-------------------------------------------------

Command 3 - NO COMMAND

Files: classes/DynArr3.h

Slides: 8-9

Modifies DynArr2.h by showing the first example of a private class method, copy, which can copy elements from one location on the heap pointed to by origin to another pointed to by destin

-------------------------------------------------

Command 4 - NO COMMAND

Files: classes/DynArr4.h

Slides: 8-9

Modifies DynArr3.h by using the private copy method to develop a copy constructor and assignment operator

-------------------------------------------------

Command 5 - make DynArrTest5

Files: classes/DynArr5.h and programs/DynArrTest5.cpp

Slides: 12-15

Modifies DynArr4.h by adding operators to access the first and last element, using call by reference, to show how to modify the private array, as well as how to pass const object in the event the array elements are larger than conventional types, like int, double, float, ect...

-------------------------------------------------

Command 6 - make DynArrTest5Bad

Files: classes/DynArr5Bad.h and programs/DynArrTest5Bad.cpp

Slides: 16-17

Modifies DynArr5.h by changing the length and capacity method names to size() and capac() - the same names as the private members - to show how -Wshadow ensures naming integrity in C++

-------------------------------------------------

Command 7 - make DynArrTest6

Files: classes/DynArr6.h and programs/DynArrTest6.cpp

Slides: 18-19

Modifies DynArr5.h by adding overloaded operator[] with a return with a call by reference. DynArrTest6.cpp shows how this abstracts array operators so the access appears identical to a normal array.

-------------------------------------------------

Command 8 - make DynArrTest

Files: classes/DynArr.h and programs/DynArrTest.cpp

Slides: 18-19

Modifies DynArr6.h by adding push_back and erase to show how the array is dynamically allocated. DynArrTest.cpp shows how to call these elements to show Dynamic Operation.
