#include <stdio.h>

int main() {
  int a = 249;
  int b = 456;
  int z1, z2;

  if (a > b)
    z1 = a;
  else
    z1 = b;

  printf("The maximum among a and b is: %d\n", z1);

  z2 = (a > b) ? a : b;

  printf("Alternate expression gives the result : %d\n", z2);

  return 0;
}
