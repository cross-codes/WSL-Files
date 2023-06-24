#!/bin/bash

files=$(find . -name "*.o")

if [ -f "exe" ]; then
	rm exe
fi

if [ -n "$files" ]; then
	rm *.o
fi

gcc -c grocerystore.c && gcc -c main.c
gcc -o exe grocerystore.o main.o
./exe
