#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "intMerge.h"
#include "intMergeAux.h"

#pragma pack(1)

void mergeSort(int[], ssize_t, ssize_t);

int32_t main(int argc, char **argv) {
  FILE *file = fopen("data/marks.txt", "r");
  int array[1000];

  for (size_t i = 0; i < 1000; i++)
    fscanf(file, "%d", array + i);

  clock_t start = clock();
  mergeSort(array, 0U, 1000);
  clock_t end = clock();

  printf("Time taken: %lf s\n", (double)(end - start) / (CLOCKS_PER_SEC));

  return 0;
}

void mergeSort(int array[], ssize_t start, ssize_t end) {
  if (end - start < 1)
    return;

  ssize_t mid = (start + end) / 2;
  mergeSort(array, start, mid);
  mergeSort(array, mid + 1, end);

  merge(array, start, mid, end);
}

void merge(int array[], ssize_t start, ssize_t mid, ssize_t end) {
  int *buffer = (int *)malloc(sizeof(int) * (end - start + 1));
  mergeAux(array, start, mid, array, mid + 1, end, buffer, 0, end - start);

  for (ssize_t i = 0; i < end - start + 1; i++)
    array[start + i] = buffer[i];

  free(buffer);
}
