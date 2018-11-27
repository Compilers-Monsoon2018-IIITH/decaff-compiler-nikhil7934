# Compiler for Decaf language

Compiler to produce llvm IR for a given code in decaf language with specifications as explained

## Prerequisites

	Bison and Flex installed to work with C++

	llvm compiler installed

## Usage

Navigate to the Directory and then run

	make

This should generate a excutable file 

	./calc < "<program here.....>"

Test files are in the folder **test-programs**

## Files
	
	Bison File: calc.yy
	
	Flex File: calc.ll

	Scanner Files: scanner.h

	AST Files: ast.h ast.cc

	Visitor Pattern: PostFixVisitor.h

	Driver Files: diver.cc driver.h


## Description

Compiler uses Visitor Pattern, performs parsing of the program and starts constructing the AST.

Code Generation yet to be implemented.

This code has been tested on ubuntu. 
If this does not works with any other linux distro,try to check the installation process of bison, flex and llvm for that particular distro. 
Also Make file might not work with all the linux distros, so you need to change the linking part in the compilation process yourself.


	Can Parse Decaf syntax and 

	Can Create AST for any and all valid syntax of decaf language.

