#include <stdio.h>

char find(int lst1[], int lst2[]);

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[] = {10, 12, 14, 16, 18, 19, 9};

  printf("Found a match? : %c\n", find(a, b));

  return 0;
}

char find(int a[], int b[]) {
  int i, j;

  for (i = 0; i < 9; ++i)
    for (j = 0; j < 7; ++j)
      if (a[i] == b[j])
        goto found;

  return 'N';
found:
  return 'Y';
}
