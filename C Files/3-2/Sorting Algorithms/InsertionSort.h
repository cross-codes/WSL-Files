#pragma once
#include <stddef.h>

constexpr inline void swap(int *array, size_t idx1, size_t idx2) {
  int temp = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = temp;
}

constexpr inline void insertionSort(int *array, size_t n) {
  for (size_t i = 1; i < n; i++) {
    size_t j = i;
    while (j > 0 && (array[j - 1] > array[j])) {
      swap(array, j, j - 1);
      j--;
    }
  }
}
