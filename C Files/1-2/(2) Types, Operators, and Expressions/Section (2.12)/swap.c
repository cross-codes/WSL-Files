#include <stdio.h>

int main() {
  int a = 210;
  int b = 23;

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  printf("%d, %d\n", a, b);

  return 0;
}
