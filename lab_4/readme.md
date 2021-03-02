My current files for the lab 4 assignment are titled:
>'shell.c' (this is an updated version of the very buggy 'individual_lab2.c' that was originally created in lab_2)
>'shell_history_structure.c' (this is an array in a vector that we created in lab_3)

RECENT UPDATES

In the new shell (shell.c), the changes were from lines 104 to 107, in the execute function.
within main, I load the history in files lines 208 to 213 and clean up history in lines 220 to 228.
This code still does not compile, and the areas for improvement are in reading from the file, and the syntax where I write to the history list in the lsh_execute function.

Recent test:
My most recent test was a simple 'Hello World!' print statement, where the function was written in one folder, imported with an #include statement, then called with another folder. (files: test_print_statement.c and test_print_statement_main.c)

TESTING

Upcoming tests:
My next tests will simply look at different parts of the program in small, controlled environments, until I get the code working.
Test1: Read a list from a file into an array data structure, add to the array, then write the data back to the file and close the structure.
Test2: Isolate the code that actually writes to the structure (lines 104 to 107, within the lsh_execute function

Working Questions:
What are the advantages of using an array in a vector versus using a linked list?
Do I need to change any of the types in the vector to get this to run, given that the vector was tested with numbers?
Is lsh_execute the best place to write to the history list? Or should I be writing to the list at an earlier process in the shell?
