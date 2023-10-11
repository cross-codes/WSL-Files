#!/bin/bash

files=$(find . -name "*.o")

if [ -f "exe" ]; then
	rm exe
fi

if [ -n "$files" ]; then
	rm *.o
fi

gcc -c defs.c && gcc -c main.c
gcc -o exe defs.o main.o
./exe
