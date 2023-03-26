#include <stdio.h>

/*Shell sort: sort v[0], v[1], ... , v[n-1] into increasing order*/

void shellsort(int list[], int length);

int main() {
  int nums[20] = {1, 4, 5, 7, 5, 7, 10, 12, 0};
  int i;

  shellsort(nums, 9);
  for (i = 0; i < 9; ++i)
    printf("%d ", nums[i]);
  printf("\n");

  return 0;
}

void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}
