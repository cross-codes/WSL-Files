#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000

void swap(int *, ptrdiff_t, ptrdiff_t);
ptrdiff_t modifiedPartition(int *, ptrdiff_t, ptrdiff_t, ptrdiff_t);

int32_t main(int argc, char **argv) {
  int *array = (int *)malloc(sizeof(int) * N);

  for (size_t i = 0; i < N; i++)
    array[i] = rand() % 2;

  for (size_t i = 0; i < N; i++)
    printf("%d ", array[i]);

  printf("\n");
  printf("\n");

  ptrdiff_t pos = modifiedPartition(array, 0, N - 1, 12);

  for (size_t i = 0; i < N; i++)
    printf("%d ", array[i]);

  printf("\n");

  free(array);
  return 0;
}

void swap(int *array, ptrdiff_t i, ptrdiff_t j) {
  int temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}

ptrdiff_t modifiedPartition(int *array, ptrdiff_t startIdx, ptrdiff_t endIdx,
                            ptrdiff_t discard) {
  int x = array[endIdx];
  ptrdiff_t i = startIdx - 1;
  for (ptrdiff_t j = startIdx; j < endIdx; j++) {
    if (array[j] < x) {
      i++;
      swap(array, i, j);
    }
  }

  swap(array, i + 1, endIdx);

  return i + 1;
}
