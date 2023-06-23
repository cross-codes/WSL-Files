rm exe && rm *.o
gcc -c defs.c && gcc -c main.c
gcc -o exe defs.o main.o
./exe
