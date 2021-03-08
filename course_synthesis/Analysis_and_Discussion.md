**Please start with this directory's readme file if you haven't already read it.

ANALYSIS AND DISCUSSION

ANALYSIS
------talk about emergent bahavior and core principles of good design???

During my first tests, I was not able to get my clock counter to go above zero. When I had my task iterations- which run some of the functions in my cache- above 1 I got the error message "segmentation fault (core dump)." I was having seg fault issues earlier in the creation of this project as well, which I figured I would circle back to after setting up the test harnesses, pthreads, and clocking mechanisms. The situation I'm in now with the code really exemplifies why it's important to build in C one step at a time, and implement smaller experiements along the way to test hypotheses. There are many areas in my code where I would love to go back and set up experiments to learn more about how it works.

Ultimately, I was able to get an actual number on the clock by using a previous version of my code from before the segmentation faults started showing up. You can read more about this in the 'timing test' section of this analysis.

SEGMENTATION FAULTS

Before we go any further, I wanted to take this opportunity to look more into what a segmentation fault is, what causes it, and what might be causing the segmentation faults in this particular program.

Simply put, a segmenatation fault appears when we try to access memory that we do not have access to. For example, trying to access something that does not exist or that we do not have permission to use. Core dumps will happen when we try to do things like write to read only data or access corrupted memory locations.

I know that seg faults have to do with memory, so any places where I should be using a malloc function will be suspect as I approach the bugs. My first two guesses with this particular program are that I have an issue with the range of my array, and indices I am trying to access, or that I have an error in my pointers, which may not actually point to the nodes I think they do. I will speak more to to the array's errors in the tradeoffs section.

TIMING TEST

My goal for the timing test was to compare the time of a run without concurrent threading, to the time of a run with concurrent threading. I used the clock() function, but unfortunately none of my tests went above zero on the counter. One approach to solving this problem is to increase the number of iterations that the test runs. I got a seg fault when I tried to do this, but a way to fix that would be to revert to the most recent version of my program that was free of seg faults, and iterate that many many times.

When I edited my program to before the get() and put() functions were entered (to avoid a segmentation fault), I was able to actually get a number on the clock. I tried implementing and freeing my cache 1000 times. When I did this with two threads, it was clocked at 0.046875 seconds. When I did this same task with six threads, it was clocked at 0.140625 seconds. The lesson that I draw from this is that using concurrent threads is not necessarily faster and that concurrency for concurrency's sake should be avoided.

DISCUSSION

This section will discuss the biggest learnings from this assignment, as well as any tradeoffs that I faced in creating this program, and the consequences of those tradeoffs.

One idea that was more firmly established was the importance of working on these problems outside of the computer. I drew many diagrams offscreen at the start, and recreating the flowchart of the project with what I know now would be my next step toward improving the design.

I learned that there are several terminal commands to help zero in on what is causing a seg fault. I was able to use some gdb to find the function that one of my segmentation faults was happening in. Once I found the function I made ample use of print statements to get closer to the error point. Because most of my errors up until this point have been mainly compiling errors, using print statements to debug in C was relatively new, and I had a lot of fun gaining more experience in that arena.

TRADEOFFS

The first design tradeoff that I made was to use the 'keys' as indices for my array hashtable. The only information I actually stored in the array was a pointer to the node in the linked list that had the corresponding value. I thought that this would be the simplest way to approach the hashtable because I wouldn't need to convert any keys to hashvalues, but looking back I believe that I missed a crucial level of abstraction here. 

There are many limitations to actually using the keys as indices in an array in the way that I did. The first limitation is that it doesn't allow us to take in any strings as keys. The second is that we couldn't really work with keys that were larger than the capacity or size of our list, because the keys needed to be indices into the list. Theoretically, if our list was only four elements long, then the only keys available for us to use are 0, 1, 2, and 3. Additionally, unless this list is initialized somehow with NULL values, we cannot start with the key or index 3 as the starting value in our list. We would need to start with index 0 as the first key item in the list. The more I think about it, I believe this array initialization and structure is the primary source of our segmentation faults.

If we had another layer of abstraction here, we would actually have a hashfunction that takes our key and assigns it to an index in the array. This way, we would not be limited to only using keys that are within the indices available.

One tradeoff to note with using a hashmap is that this gives us the possibility for hash collisions, where two different keys are trying to use the same hash value.

A second design tradeoff was trying to get by without using some of the functions that were suggested for our doubly linked lists and arrays back in module 3. In particular, the boolean functions containsItem() and isEmpty(). 

I initially decided to create the implementation without including these functions because I thought they would be a waste of space, but I ended up needing them enough that it would have been worth it to spend a little bit more time creating these functions at the beginning. It would have made my code cleaner to have a function for these checks, instead of trying to check without a function whenever it came up.

A third design tradeoff was to include both size and capacity in my structs. My initializeCache() function took in a capacity, and initialized both the vector and the doubly linked list with the capacity. I initially thought it would be helpful to have capacity as a field on all of my structs, but during implementation this led to confusion about which struct's size or capacity to use, and when. Ultimately, there were too many unnecessary variables here and breaking it down to only the necessary ones would have been much cleaner and less expensive.

Lastly, my final design tradeoff was in the way I chose to organize my code. I ended up writing the doubly linked list, the array, and all of the cache functions in the same file. If I were to repeat this project I would try modularizing the files. At the beginning, I didn't want to put these three components in different files, because I thought it wasn't a good use of time to focus so much on setup, but after creating the project I think spending some time at the beginning to build a clear and solid foundation in separate pieces would have helped quite a bit. It would have helped me to think more clearly through how the pieces fit together, and it also would have helped me figure out how to ensure mutual exclusion for the data. It also would have been helpful at the testing phase, for testing and building harnesses for smaller components of the project at a time.

