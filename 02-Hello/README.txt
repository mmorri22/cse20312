These code segments follow the order of Lecture 02 for CSE 20312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse20312/lecture-notes/

The order of compilation and files to understand the design is as follows:

-------------------------------------------------
Command 1 - make intPtr

Files: intPtr.cpp

Slides: 9-12

A fundamental example of a pointer. Students will understand the three main properties of a pointer.

-------------------------------------------------
Command 2 - make void1

Files: void1.cpp

Slides: 19, 21

Shows how to allocate a void pointer and memory on the heap, and print the address of the base address on the heap.

-------------------------------------------------
Command 2 - make char1

Files: char1.cpp

Slides: 21-22

Shows how to allocate a char pointer and memory on the heap, and print the address of the base address on the heap.

-------------------------------------------------
Command 3 - make array1

Files: array1.cpp

Slides: 26

Shows how to allocate a char pointer and memory on the heap, and print the address of the base address on the heap.

-------------------------------------------------
Command 4 - make void2

Files: void2.cpp

Slides: 27-28

Modified void1.cpp by showing how to iterate through the allocated memory and print all the locations by size of a character

-------------------------------------------------
Command 5 - make char2

Files: char2.cpp

Slides: 29

Modified char1.cpp by showing how to iterate through the allocated memory and print all the locations by size of a character

-------------------------------------------------
Command 6 - make array2

Files: array2.cpp

Slides: 29

Modified array1.cpp by showing how to iterate through the allocated memory and print all the locations by size of a character

-------------------------------------------------
Command 7 - make void3

Files: void3.cpp

Slides: 21-23

Modified void2.cpp by showing how to dereference a void pointer and store the information at a specific location on the heap. Also, can modify the pointer arithmetic to print different locations.

-------------------------------------------------
Command 8 - make char3

Files: char3.cpp

Slides: 24

Modified char2.cpp by showing how to dereference a void pointer and store the information at a specific location on the heap. 

-------------------------------------------------
Command 9 - make array3

Files: array3.cpp

Slides: 25

Modified array2.cpp by showing how to dereference a void pointer and store the information at a specific location on the heap. 

-------------------------------------------------
Command 10 - make void4

Files: void4.cpp

Slides: 26

Modified void3.cpp by storing all the characters of Hello, World and then iterating, printing the address location and the char value.

-------------------------------------------------
Command 11 - make char4

Files: char4.cpp

Slides: 27

Modified char3.cpp by storing all the characters of Hello, World and then iterating, printing the address location and the char value.

-------------------------------------------------
Command 12 - make array4

Files: array4.cpp

Slides: 28

Modified array3.cpp by storing all the characters of Hello, World and then iterating, printing the address location and the char value.

-------------------------------------------------
Command 10 - make helloVoid

Files: helloVoid.cpp

Slides: 29, 33

Modified void4.cpp by removing the std::endl between each character and the address so it resembles the classic "Hello, World" output. In Slide 33, this file is compared to Hello, World to show that low-level procedural programming in helloVoid.cpp is the exact same code as abstracted Object-Oriented level.

-------------------------------------------------
Command 10 - make helloChar

Files: helloChar.cpp

Slides: 30

Modified char4.cpp by removing the std::endl between each character and the address so it resembles the classic "Hello, World" output.

-------------------------------------------------
Command 11 - make helloArray

Files: helloArray.cpp

Slides: 31

Modified array4.cpp by removing the std::endl between each character and the address so it resembles the classic "Hello, World" output.

-------------------------------------------------
Command 12 - make helloArray2

Files: helloArray2.cpp

Slides: 31

Modified helloArray.cpp by changing how the characters are printed from pointer arithmetic to array operator [], showing they are equivalent at different levels of abstraction, but these produce the same result.

-------------------------------------------------
Command 13 - make helloArray3

Files: helloArray3.cpp

Slides: 32

Modified helloArray.cpp by saving the characters as an array to the char* hello using the "" notation, and then printing the entire array, but these produce the same result.