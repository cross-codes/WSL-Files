#include <stdio.h>

#define EXIT_SUCCESS 0

void swap(int *px, int *py);

int main() {
  int a = 3, b = 4;

  swap(&a, &b);

  printf("The values have been swapped! a = %d and b = %d\n", a, b);

  return EXIT_SUCCESS;
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
