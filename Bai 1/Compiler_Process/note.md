# Author: Nguyen Minh Duc
# Email : minhducnguyen1205@gmail.com

# Compiler process
To compile and run a C/C++ programme, we will have to follow this process.
## Stage 1: Preporcessing
In this status, file main.c compiles into file main.i
```bash
+ Command: gcc -E main.c -o main.i
```
### The meaning of file main.i:
+ Replace all header files and predefined file in #include tag with their contents
+ Replace all macros which have been defined by #define with the contents which have been defined by those macros
+ Delete all comments in file main.c
+ 
## Stage 2: Compiler
File main.i will be compiled into file main.s by using this command
``` bash

gcc -S main.i -o main.s
```
### The meaning of file main.s
+ turning all the codes in high-level programming languages to assembler, which is a low-level programming language that can directively interact with CPU, register or memory partitions, etc

## Stage 3: Assembler
File main.s will be compiled into file main.o using this command
```bash
gcc -c main.s -0 main.o
```
### The meaning of file main.o
+ Contain of the decoded code into binary or hex, so that computers can understand and implement.

## Stage 4: Linker
Link all file.o into the only file.o using this command
```bash
gcc main1.o main2.o main.o ... -o main
```
## Stage 5: Execute programme
using
```bash
./main
``` 
 