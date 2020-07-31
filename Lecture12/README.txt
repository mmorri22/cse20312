These code segments follow the order of Lecture 09 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - make countSort1

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSort1.cpp

Slides: 6

Puts elements in a Dynamic Array, iterates through, and prints the largest number

-------------------------------------------------

Command 2 - make countSort2

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSort2.cpp

Slides: 7-8

Modifies countSort1.cpp by adding a HashTable with the number of buckets equal to the largest number. Prints all the buckets and shows the buckets up to the largest number are active. But the resizing means there are many more that are empty.

-------------------------------------------------

Command 3 - make countSort3

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSort3.cpp

Slides: 9-10

Modifies countSort2.cpp by iterating through the initial array, and then increment the corresponding bucket’s value. Prints all the buckets and shows that we have the successful sort, but a lot of extra space.

-------------------------------------------------

Command 4 - make countSort

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSort.cpp

Slides: 11

Modifies countSort3.cpp by only printing the buckets with values greater than 0, and showing the emitting.

-------------------------------------------------

Command 4 - make countSortImpr1

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSortImpr1.cpp

Slides: 12-13

Modifies countSort.cpp by only hashing the values in the array, not creating the number of buckets. We see that the elements are not in order anymore, but that is acceptable with the Hash Table.

-------------------------------------------------

Command 5 - make countSortImpr2

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSortImpr2.cpp

Slides: 14

Modifies countSortImpr1.cpp by including the printHash function. This won't work, because we are accessing elements even if they are not in the hash, and we do not have a try / throw / catch block.

-------------------------------------------------

Command 6 - make countSortImpr

Files: classes/LinearProbe.h, classes/DynArr.h and programs/countSortImpr.cpp

Slides: 15

Modifies countSortImpr2.cpp by adding the necessary try / throw / catch block. Works with the least amount of memory.

-------------------------------------------------

Command 7 - make countSortSTL

Files: programs/countSortSTL.cpp

Slides: 16-18

Modifies countSort.cpp by using the std::vector and std::unordered_map from the C++ STL. Shows the pros and cons of using the STL

-------------------------------------------------

Command 8 - make sepChain

Files: classes/LinearProbe.h, classes/DynArr.h and programs/sepChain.cpp

Slides: 22-25

Shows how to use a Dynamic Array to Separately Chain a Hash table. An operator<< is added to DynArr.h for ease of printing.

-------------------------------------------------

Command 9 - make bucketSort

Files: classes/LinearProbe.h, classes/DynArr.h, classes/SorDynArr.h and programs/bucketSort.cpp

Slides: 26-33

First, a sorted Dynamic Array is created from a Dynamic Array using Inheritance and Polymorphism. Then, then Hash Table and Separate Chaining are used to perform Bucket Sort.
