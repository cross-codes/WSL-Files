#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma pack(1)

void swap(int *, ptrdiff_t, ptrdiff_t);
ptrdiff_t lomutoParition(int *, ptrdiff_t, ptrdiff_t);

void quickSort(int *, ptrdiff_t, ptrdiff_t);
void measure__(void (*)(int *, ptrdiff_t, ptrdiff_t), char *, size_t);

int32_t main(int argc, char **argv) {
  measure__(quickSort, "int0.txt", 1000);
  measure__(quickSort, "int1.txt", 1000);
  measure__(quickSort, "int2.txt", 1000);
  measure__(quickSort, "int3.txt", 50);
  measure__(quickSort, "int4.txt", 1000);
  measure__(quickSort, "int5.txt", 1000000);

  printf("\n");
  return 0;
}

void swap(int *array, ptrdiff_t i, ptrdiff_t j) {
  int temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}

ptrdiff_t lomutoParition(int *array, ptrdiff_t startIdx, ptrdiff_t endIdx) {
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

void quickSort(int *array, ptrdiff_t p, ptrdiff_t r) {
  if (p < r) {
    ptrdiff_t q = lomutoParition(array, p, r);
    quickSort(array, p, r - 1);
    quickSort(array, q + 1, r);
  }
}

void measure__(void (*idempotent)(int *, ptrdiff_t, ptrdiff_t), char *fileName,
               size_t length) {
  FILE *file1 = fopen(fileName, "r");

  int *array = (int *)malloc(sizeof(int) * length);

  if (file1 == NULL) {
    printf("Error in opening file\n");
    return;
  }

  for (size_t i = 0; i < length; i++)
    fscanf(file1, "%d", &array[i]);

  clock_t start = clock();
  idempotent(array, 0, length - 1);
  clock_t end = clock();

  printf("Time Taken: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

  free(array);
}
