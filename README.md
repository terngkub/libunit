# libunit
A unit testing framework project.

### About this project
* This is a Rushes project at [École 42](https://42.fr).
* Rushes project is a 2 days group project on weekend incremented to a normal school curriculum.
* My teammate is [Jean-Judicaël Daufin](https://www.linkedin.com/in/jean-judica%C3%ABl-daufin-2a4167135/).
* The objective of this project is to create a framework to unit test the code in C.
* The project divided into 3 parts:
	* framework: the framework of the unit testing
	* test: the test examples that will output all the test case.
	* real-test: the real test cases of some of my functions from [libft](https://github.com/terngkub/libft). (However, I broke the code to show the variety of the results.)

### How to run the program
Each parts of the project has it own Makefile so you can just run make command in each part.
```
make
```

For "tests" part, run
```
./bt_strcpy_basic
```

For "real-tests" part, run
```
./rt_project
```

### The idea behind the project
The idea is that we have to run the code to test another code. The problem is that sometime when the tested code is broken, the program will terminate immediately. To prevent that, we create a child process with fork() and then test the codes in that child process instead. If the code is broken and the child is terminated, no problem, we send the result and get it in the parent process with wait().

We also do the bonus of this project by checking if the program take too long to execute or not. If it take too long, it will be timeout. In this case, we use alarm() to set the time. When the time is out, the alarm will send alarm signal. Then, capture that signal with signal() and terminate the process.

For another bonus, we deal with case that the tested program that output something in stdout. If we normally run the program, the tested program will output something in our stdout (like testing printf for example) and we don't want that. In this case we redirect the stdout into a pipe (creating using pipe()) and then compare the output with the expected output instead.

### My thought about this project
Working in group in a short time is quite challenging. However, my teammate has a good skill and he is dedicated. We divided the work nicely and everythings was completed long before the deadline so we have time to do the bonus. We got 115/100 (15 points for the bonus). It's a great experience to do this Rushes.
