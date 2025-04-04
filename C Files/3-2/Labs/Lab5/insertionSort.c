#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#pragma pack(1)

#define SIZE 50000

void recursiveInsertionSort(int *, int);
void iterativeInsertionSort(int *, int);

int32_t main(int argc, char **argv) {
  FILE *ptr = fopen("data/numbers50000.txt", "r");

  int recursive[SIZE], iterative[SIZE];
  memset(recursive, 0x00, sizeof(int) * SIZE);
  int i = 0;
  while (fscanf(ptr, "%d", &recursive[i++]) != EOF)
    ;

  memcpy(iterative, recursive, sizeof(int) * SIZE);
  fclose(ptr);

  clock_t start = clock();
  recursiveInsertionSort(recursive, SIZE);
  clock_t end = clock();

  printf("Recursive: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  iterativeInsertionSort(iterative, SIZE);
  end = clock();

  printf("Iterative: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}

void recursiveInsertionSort(int *arr, int n) {
  if (n <= 1)
    return;

  recursiveInsertionSort(arr, n - 1);
  int last = arr[n - 1], j = n - 2;

  while (j >= 0 && arr[j] > last) {
    arr[j + 1] = arr[j];
    j--;
  }

  arr[j + 1] = last;
}

void iterativeInsertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int last = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > last) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = last;
  }
}
