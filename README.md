# Dictionary Implementation. A project for Estrutura de Dados Básicas I (EDB I)

## Introduction

This programming project implements the idea of dictionary data structure. Through Hashing, we will associate each account info to a created key. Since it is possibly to have the same account number for different agencies, we can't work with a key that receives only these 2 informations. For pratical use, we are considering a key to be a group of the *client's name, bank code, agency number* and *bank accounts number* data.

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that ```git``` is a tremendous tool for any programmer, then we must have git installed.

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
