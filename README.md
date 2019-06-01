# PRO2 Subject Project
Lisp interpreter in C++
## Getting Started
This is the PRO2 subject course project which consists in developing an interpret in C++ language for basic arithmetic and boolean operations written in Lisp form. The program also allows to define new operations, variables and arrays.
The whole project is documented using Doxygen.
### Dependencies
```
g++ compiler
build-essential
```
### Installing
The project comes with a makefile. In order to compile and run the program, do the following steps:
```
Unpack the project
$ make program.exe
$ ./program.exe
```
### Testing
```
$ ./program.exe < TEST_Input.txt
```
The Testing file has invalid operations on purpose.

You should expect the following outputs:  
Invalid operations will be resolved as "_indefinit_".  
Operations with negative result are also _indefinit_.  
Arithmetic and boolean operations will produce a single output containing the result of the operation.  
Array definitions will produce a single output printing the array.  
Definitions will produce a single output with the definition identifier (#<id>).  
Variable definitions will produce a single output with the variable name and the variable value.  
  
At the end of the output you can find all the variables with its final values and all the operation definitions with its identifiers.
