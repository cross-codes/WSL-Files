#pragma once
#include <stddef.h>

void insertionSort(int *__array, size_t __SIZE) {
  for (size_t j = 1; j < __SIZE; j++) {
    size_t i = 0;
    while (__array[j] > __array[i])
      i++;
    int m = __array[j];
    for (size_t k = j; k > i; k--)
      __array[k] = __array[k - 1];

    __array[i] = m;
  }
}
