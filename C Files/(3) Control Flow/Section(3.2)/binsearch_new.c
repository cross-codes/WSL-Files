#include <stdio.h>

int binsearch(int var, int list[], int length);

int main() {
  int lst[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  printf("%d\n", binsearch(6, lst, 15));
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }
  if (x == v[mid])
    return mid;
  else
    return -1;
}
