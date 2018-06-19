# Dictionary Implementation. A project for Estrutura de Dados Básicas I (EDB I)

## Introduction

This programming project implements the idea of dictionary data structure. Different from most data structures, dictionary uses a associative container, which means that it retrieves information based on data(or keys). Data Structures such as vector, for exampple, uses sequence container, retrieval based on position.
More specifically, we will be implementing a Dictionary with Array List(DAL) and a Dictionary with Sorted Array List(DSAL). These two different implementations, differs from each other when about Algorithm Complexity, depending on operations.

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that ```git``` is a tremendous tool for any programmer, then consider that git is already installed.

It is also expected for user to have installed [doxygen](https://en.wikipedia.org/wiki/Doxygen ) program. This will automatically generate documentation for code. Not a necessary package to compile and run program, but it is a tool to guide user through code functions. To install `doxygen` on UBUNTU, for example:

```bash
$ sudo apt-get install doxygen
```
To compile we will use a makefile, so compilations may be more dynamic and automatic.
```bash
# Using 'git clone' to clone this repo into desired directory:
$ git clone https://github.com/Codigos-de-Guerra/Dictionary-Implementation.git

# Enter repo:
$ cd Dictionary-Implementation

# To compile the whole project and also generate documentation, insert 'make' inside root of path:
$ make

# To clean up all remaining trash data and files, such as the binary ones, insert 'make clean':
$ make clean
```

## How to execute

Now, we show how to run the program. 
```bash
# To execute program:
$ ./dict
```

## GitHub Repository:

*https://github.com/Codigos-de-Guerra/Dictionary-Implementation*

## Authorship

Program developed by [_Daniel Oliveira Guerra_](https://github.com/Codigos-de-Guerra) (*daniel.guerra13@hotmail.com*), 2018.1

&copy; IMD/UFRN 2018.
