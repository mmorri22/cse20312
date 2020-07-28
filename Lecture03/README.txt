These code segments follow the order of Lecture 03 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:

-------------------------------------------------
Command 1 - make voidNodeBad

Files: voidNodeBad.cpp

Slides: 1

Modifies voidNode.cpp from Lecture 02 - Part 2 to show what happens when pointer arithmetic is performed incorrectly, which leads to incorrect values printed on the output even when the values are stored correctly on the input.

-------------------------------------------------
Command 2 - make voidNodeBad2

Files: voidNodeBad.cpp

Slides: 2

Modifies voidNode.cpp from Lecture 02 - Part 2 to show that even when the information is allocated correctly, it can still be inefficient.

-------------------------------------------------
Command 2 - make structSimple

Files: structSimple.cpp

Slides: 8-11

Performs the same logical tasks as voidNode from Lecture 02 - Part 2, but is encapsulated as a struct, which abstracts imperative and procedural complexity away from the user.

-------------------------------------------------
Command 3 - make structMod

Files: structMod.cpp

Slides: 12

Modifies structSimple.cpp by changing the members of the struct and prints the results.

-------------------------------------------------
Command 4 - make classNode

Files: classNode.cpp

Slides: 14-15

Performs the same tasks as structNode.cpp and voidNode.cpp, except data hiding is implemented by making the class members private. Now the student can see the construction of the node at the imperative, procedural, and object oriented levels of abstraction.

-------------------------------------------------
Command 5 - make classMod

Files: classMod.cpp

Slides: 16

Modifies classNode.cpp by adding set methods to change the private members of the Node class

-------------------------------------------------
Command 6 - make classBad

Files: classBad.cpp

Slides: 18-19

Modifies classNode.cpp by changing the order of the member initialization list, which is the same as the order in voidNodeBad2.cpp, showing that PQC flags ensure that data is structured in a manner that is efficient.

-------------------------------------------------
Command 7 - make classBad2

Files: classBad.cpp

Slides: 20

The Makefile uses the PQC flags to show that -pedantic and -weffc++ require that the C++ code you write structures the data efficiently.

-------------------------------------------------
Command 8 - make const

Files: const.cpp

Slides: 22

A simple example of a global const variable.

-------------------------------------------------
Command 9 - make funcOver

Files: funcOver.cpp

Slides: 24-25

A simple example of function overloading.

-------------------------------------------------
Command 10 - make ambig

Files: ambig.cpp

Slides: 26

An example of ambiguous function overloading, leading to a compiler error

-------------------------------------------------
Command 11 - make template

Files: template.cpp

Slides: 29-30

A fundamental example of template functions and generic types.


