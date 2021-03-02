Welcome to my repository for the CS5008 course.

WHAT IS IN THIS REPO?

In this repository you will find my labwork from the CS5008 course. Much of this work was inspired by Vido's code in the videolectures on Canvas. Much of this work was also heavily influenced by discussions with my TA, Sean, in class discussions, and discussions with my teammates, Ian and Yichen. The 'Example' directory contains some scratch code, mostly from the beginning of the semester when I was practicing basic concepts. The rest of the directories (lab_1 through lab_6) contain my individual work from those modules. Many of the individual labs are still works in progress, and each directory has a readme file that explains the different code files, instructions on code compilation, recent updates, and upcoming tests.

WHERE AM I EDITING MY CODE?

I began this course writing and editing code in Vim, and uploading it to github through a khoury server that I SSH'd into from my computer. Since I am working on a windows and not a Mac, I downloaded PuTTY, an open source terminal emulator, in order to successfully SSH into the Khoury system. 

I decided to switch over to VSCode to edit my code because I like the user interface there better. Switching over to VSCode turned out to be a more comprehensive process than I expected. There was a lot of troubleshooting along the to try and understand why my "hello world" program wasn't working the way I wanted to. The steps I ended up taking were:

>Download VSCode
>Download GCC and Clang into my terminal to compile code

At this point I got my "hello world" running, and then needed to pull from my git repo and push my code back. I realized that the terminal commands I was used to were all in linux, so needed to figure out how to get a linux emulator in my terminal. This emulator ended up running in Ubuntu.

>Download Ubuntu
>Download windows subsystem for linux
>Configure Ubuntu and WSL
>Use sudo to access privileges and download GCC, Clang, and Valgrind
>Configure my terminal with github enterprise

WHAT IS MY WORKING PROCESS?

My approach to tackling these labs was to watch vido's videos and code along with him, then think through the structure of what I was working on on paper. I would write the whole code and then go back and look for bugs. 

I have since updated my working process to better decompose the problem I am working on as I approach it-- that is, take little chunks of the problem at hand and write simple code to test it out, make sure I've got that working, then move on to the next piece. A great example of this is in lab_4, with the modular files. I wrote out simple 'test_print_statement.c' and 'test_print_statement_main.c' files to make sure my file modularization was working properly, and am now moving on to sort out the other bugs. If I were to do this whole process again, I would have started with the smaller experiments before trying to build the entire program.