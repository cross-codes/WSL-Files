rm exe
rm *.o
gcc -c grocerystore.c && gcc -c main.c
gcc -o exe grocerystore.o main.o
./exe
