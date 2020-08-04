These code segments follow the order of Lecture 05 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - make fib

Files: fib.cpp

Slides: 16-19

fib.cpp contains a recursive implementation of computing the nth value of the Fibonacci sequence. The slides show the drawback to this approach, which is when excessive calls are made on the stack

-------------------------------------------------

Command 2 - make merge1

Files: merge1.cpp

Slides: 23

merge1.cpp contains the first step in designing the Merge Sort algorithm. This code creates two int arrays and passes them by reference and prints the initial order.

-------------------------------------------------

Command 3 - make merge2

Files: merge2.cpp

Slides: 24-26

merge2.cpp builds on merge1.cpp, and shows how to divide and conquer until we reach the base cases. No sorting has been performed yet, so the print out will be just the min and max values at each level. The animations correlate with the printed results.


-------------------------------------------------

Command 4 - make merge3

Files: merge3.cpp

Slides: 27-28

merge3.cpp builds on merge2.cpp, with the initial swaps for if the subarray is a length of 1 or 2. Only those values are swapped, so you can see the process building towards the eventual full swap.

-------------------------------------------------

Command 5 - make merge4

Files: merge4.cpp

Slides: 27-28

merge4.cpp builds on merge3.cpp, and the swap for all the subarrays are shown and printed to the user. The output shows all the swaps at all the stages, so you can see the full algorithm flow.

-------------------------------------------------

Command 6 - make merge

Files: merge.cpp

Slides: 27-28

merge.cpp modifies merge4.cpp in two ways. First, all the intermediate print steps are removed to simplify the output. Second, the code has been modified to go from only being able to sort integers to being able to sort any type by providing templated functions with generic types.
