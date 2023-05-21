#include <stdio.h>

int akshaj(int num) { return num; }

int ayush(int num) { return -num; }

int main() {
  int (*akshaj_ptr)(int);
  akshaj_ptr = ayush;

  if ((*akshaj_ptr)(5) > 0) {
    printf("What is up!");
  } else {
    printf("Go away!");
  }

  return 0;
}
