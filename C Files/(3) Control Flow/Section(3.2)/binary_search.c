#include <stdio.h>

/*Binary Search: find x in v[0] <= v[1] <= v[2] <= ... <= v[n-1]*/

int binsearch(int var, int list[], int length);

int main() {
  int lst[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  printf("%d\n", binsearch(6, lst, 15));

  return 0;
}

int binsearch(int x, int lst[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < lst[mid])
      high = mid - 1;
    else if (x > lst[mid])
      low = mid + 1;
    else /*Found a match*/
      return mid;
  }
  return -1;
}
