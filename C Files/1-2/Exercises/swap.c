#include <stdio.h>

int main() {
  int a = 43, b = 69;

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  printf("The value of a and b are: %d and %d\n", a, b);

  return 0;
}
