#include <stdio.h>

int main() {
  int x = 1, y = 2, v[2] = {0, 1};
  int *ip;

  printf("%d\n", *ip);
  ip = &x;
  printf("%d, %d\n", ip, *ip);
  y = *ip;
  printf("%d\n", y);
}
