#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void __merge(int *__array, size_t __leftIdx, size_t __midIdx,
             size_t __rightIdx) {
  size_t nL = __midIdx - __leftIdx + 1, nR = __rightIdx - __midIdx;

  int *L = (int *)malloc(sizeof(int) * nL);
  int *R = (int *)malloc(sizeof(int) * nR);

  memset(L, 0x0, sizeof(int) * nL);
  memset(R, 0x0, sizeof(int) * nR);

  for (size_t i = 0; i < nL; i++)
    L[i] = __array[__leftIdx + i];

  for (size_t j = 0; j < nR; j++)
    R[j] = __array[__midIdx + 1 + j];

  size_t i = 0, j = 0, k = __leftIdx;

  while (i < nL && j < nR) {
    if (L[i] <= R[j])
      __array[k] = L[i++];
    else
      __array[k] = R[j++];
    k++;
  }

  while (i < nL) {
    __array[k] = L[i++];
    k++;
  }

  while (j < nR) {
    __array[k] = R[j++];
    k++;
  }

  free(L), free(R);
}

void mergeSort(int *__array, size_t __leftIdx, size_t __rightIdx) {
  if (__leftIdx >= __rightIdx)
    return;
  size_t q = (__leftIdx + __rightIdx) >> 1;
  mergeSort(__array, __leftIdx, q);
  mergeSort(__array, q + 1, __rightIdx);
  __merge(__array, __leftIdx, q, __rightIdx);
}
