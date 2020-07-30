These code segments follow the order of Lecture 03 - Part 2 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:

-------------------------------------------------
Command 1 - NO COMPILATION COMMAND HERE

Files: fact_01.h, fact_01.cpp

Slides: 4

Shows the first step in setting up a Header File. No main function, just the initial set up.

-------------------------------------------------
Command 2 - make fact_02_run

Files: fact_02.h, fact_02.cpp, fact_02_run.cpp

Slides: 5-6

Shows the creation of a function declaration in the .h file, a function definition in the .cpp file, and the function call in fact_02_run.cpp. Slide 6 also shows an example of overflow integer

-------------------------------------------------
Command 3 - make fact_03_run

Files: fact_03.h, fact_03.cpp, fact_03_run.cpp

Slides: 7

Modified the fact_02 files by adding const int global variables in the .h file, which then may be used in every .cpp file, and is used in this case to prevent the overflow

-------------------------------------------------
Command 4 - make factHeaderEx

Files: factorial.h, factorial.cpp, factHeaderEx.cpp

Slides: 8-15

Completes the fact_03 files by printing and testing the range of the factorial functions. The results are tested against Google Calculator to show the architectural level contributes to the accuracy and range of code written at the object-oriented level.