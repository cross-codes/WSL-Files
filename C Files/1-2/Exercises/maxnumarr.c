#include <stdio.h>

void shellsort(int *v, int n);

int main() {
  int arr[] = {2, 4, 12, 44, 122, 1, -1};
  shellsort(arr, sizeof(arr) / sizeof(arr[0]));
  printf("The maximum number in the array is %d\n",
         arr[sizeof(arr) / sizeof(arr[0]) - 1]);
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
