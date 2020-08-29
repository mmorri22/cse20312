These code segments follow the order of Lecture 08 - Part 2 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - make IrishTest

Files: classes/Irish.h, classes/Irish.cpp and programs/IrishTest.cpp

Slides: 11-15

Builds a base class in Irish.h and Irish.cpp, and runs the program in IrishTest.cpp

-------------------------------------------------

Command 2 - make Inherit

Files: classes/Student.h, classes/Student.cpp, classes/Faculty.h, classes/Faculty.cpp, programs/Inherit.cpp

Slides: 16-23

Develops derived classes for Student and Faculty, and then runs them as Inherited classes

-------------------------------------------------

Command 3 - make Inherit2

Files: programs/Inherit.cpp

Slides: 24-29

Calls the printInformation methods to show when you need to call this-> and when not to with derived members
