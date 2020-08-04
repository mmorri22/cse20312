These code segments follow the order of Lecture 04 - Part 2 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------
Command 1 - make exp1

Files: exp1.cpp

Slides: 13-18

Shows an example of using recursion to calculate the factorial, as well as
calculating the exponential with a hard-coded input

-------------------------------------------------
Command 2 - make exp2

Files: exp2.cpp

Slides: 19-21

This file pmodified exp1.cpp by add a function to read in a value from the command line, using std::stringstream and error checking, and use that double to obtain the exponential.

-------------------------------------------------
Command 3 - make exp

Files: exp.cpp

Slides: 22

exp builds on exp2.cpp by increasing the number of additions (recursive calls on the stack) to obtain a more accurate answer.