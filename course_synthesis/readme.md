
WHAT IS IN THIS DIRECTORY?

This directory contains my work for the CS5008 course synthesis. This is an ongoing project that will continue to grow and develop with my portfolio. The objective of this project was to produce a report and write an implementation and tests for a concurrent linked hashmap with an LRU policy.

Start with Design.md, which contains a report on my approach to this data structure, before implementing.

Then, you can find the whole code in Cache.c. I simply compile this with gcc. To run it with the testing harness, follow the instructions below.

To see tests, reach the 'recent tests' and 'upcoming tests' below, then navigate to the testing folder.
In the main testing folder, you will find a makefile for the cache and cache testing harness, using pthreads for concurrency, and a clock that prints the timing.

Note that in Cache_test_harness.c, in the Testing file, the put function is commented out in task1. This ensures that I will only call parts of my code from before the segmentation faults started happening. Note that in the main of this file, you will find two thread tests- one where the task is split between two threads and one where the task is split between 6.

Finally, navigate to the Analysis_and_Discussion to find more about my learnings throughout the project, some analysis, and a discussion of errors, debugging, and design tradeoffs.

Enjoy!

RECENT TESTS
1. Learned how to use the clock() function with a simple program.
Timing>timer.c
2. Learned how to use pthreads to run a function with a makefile, and include pthread in makefile
Testing>sample_pthread
3. Learned how to use a makefile successfully
Testing>sample_makefile
4. Ran my Cache program with pthreads and a clock (still get seg faults)
Testing>makefile
5. Revert code to have an example of it before the seg faults, and run this code through the testing harness with pthreads and the clock.

UPCOMING TESTS
1. Continue debugging the segmentation fault that happens in the get() function when we try to access previous node.
2. Isolate the array and figure out how storing pointers to nodes instead of integers in the array many impact the way it uses memory.
3. Test to see if adding in a hashfunction with another level of abstraction would allow us to have more accuraccy with our array.


RESOURCES

hashtable versus hashmap: https://stackoverflow.com/questions/32274953/difference-between-hashmap-and-hashtable-purely-in-data-structures

What is a hashmap? https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Dictionaries#:~:text=A%20dictionary%20is%20also%20called,caches%20and%20high%2Dperformance%20databases

youtube video on hashtables: https://www.youtube.com/watch?v=shs0KM3wKv8&ab_channel=HackerRank

core dump: https://www.tutorialspoint.com/core-dump-segmentation-fault-in-c-cplusplus
