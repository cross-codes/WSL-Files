#include <stdio.h>

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[10] = {10, 12, 14, 16, 18, 19, 12};
  int m, n;

  for (m = 0; m < 9; ++m) {
    for (n = 0; n < 7; ++n) {
      if (a[m] == b[n]) {
        goto found;
      } else
        printf("Not a match\n");
    }
  }
found:
  printf("Found a match %d, %d, %d\n", a[m - 1], b[n - 1], m - 1);

  return 0;
}
