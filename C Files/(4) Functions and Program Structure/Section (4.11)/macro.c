#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t temp;                                                                    \
    temp = y;                                                                  \
    y = x;                                                                     \
    x = temp;                                                                  \
  }

int main() {
  int x = 23, y = 440;

  swap(int, x, y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
