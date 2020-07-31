These code segments follow the order of Lecture 05 - Part 2 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - make tempVoidNode

Files: programs/tempVoidNode.cpp

Slides: 5-10

Modifies the voidNode.cpp from Lecture 02 - Part 2 by templating the functions used to allocate and print the values from the heap. This function prints the wrong values because g++ templates decimal values to a double automatically, so the incorrect values are printed out

-------------------------------------------------

Command 2 - make tempVoidNode2

Files: programs/tempVoidNode2.cpp

Slides: 11-12

Modifies programs/tempVoidNode.cpp by casting the decimal we want as a float to a float in the main function, which makes the values on the output correct. Compared to ESA Ariane 5 rocket explosion, since the exact same error is what caused the rocket to explode.

-------------------------------------------------

Command 3 - make template1

Files: A_1.h and template1.cpp

Slides: 13-16

In A_1.h, the first example of a templated class is given. A default and overloaded constructor are created, and their address on the heap is printed using the "this" keyword. In template1.cpp, three templated objects are created, and their location on the heap is printed using addresses and values in register

-------------------------------------------------

Command 4 - make classBad

Files: Abad.h, Abad.cpp and classBad.cpp

Slides: 17-19

In A_1.h, the first example of a templated class is given. A default and overloaded constructor are created, and their address on the heap is printed using the "this" keyword. In template1.cpp, three templated objects are created, and their location on the heap is printed using addresses and values in register

-------------------------------------------------

Command 5 - make tempTest

Files: A.h and tempTest.cpp

Slides: 20-26

Modified A.h to add the "Rule of Three" desctructor, copy constructor, and assignment operator. Also adds an operator==. In tempTest, template1.cpp is modified to call the operators to show their effectiveness.




