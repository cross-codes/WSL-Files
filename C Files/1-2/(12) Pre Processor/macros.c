#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define CUBE(x) (x * x * x)
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define MIN5(a, b, c, d, e) MIN(MIN(MIN(a, b), MIN(c, d)), e)

int main() {
  int side = 5;
  int another_side = 10;
  printf("%d\n", CUBE(side + another_side));
  printf("%d\n", MIN5(1, 3, 2, -1, 5));
  return 0;
}
