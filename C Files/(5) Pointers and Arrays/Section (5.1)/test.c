#include <stdio.h>

int main() {
  int x = 1, y = 2, v[2] = {0, 1};
  int *ip;

  ip = &x;
  printf("%d\n", ip);
  y = *ip;
  printf("%d\n", y);
}
