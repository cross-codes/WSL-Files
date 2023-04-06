#include <stdio.h>

void qsort(int array[], int left, int right);
void swap(int array[], int i, int j);

int main() {
  int arr[] = {2, 4, 1, 2, 4, 5, 4, 2, 1};
  int i;

  qsort(arr, 0, 8);
  for (i = 0; i < 9; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

void qsort(int v[], int left, int right) {
  int i, last;

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
