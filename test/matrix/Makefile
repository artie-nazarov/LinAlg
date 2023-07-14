# Makefile for various test scripts

# Compiler shortcuts
CC=g++
FLAGS=-Wall -Werror -pedantic
STD=-std=c++11

# Dependency shortcuts
MAT_DEP=../../lib/matrix/matrix.hpp


transpose_test: transpose_test.cpp $(MAT_DEP)
	$(CC) $(STD) $(FLAGS) -o transpose.tst transpose_test.cpp -I/$(MAT_DEP)

clean:
	rm -f transpose_test.tst 