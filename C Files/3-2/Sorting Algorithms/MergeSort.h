#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int *merge(int L1[], size_t n1, int L2[], size_t n2) {
  int *L = (int *)malloc((n1 + n2) * sizeof(int));
  size_t ptr = 0, ptr1 = 0, ptr2 = 0;

  memset(L, 0, (n1 + n2) * sizeof(int));

  while (ptr1 < n1 && ptr2 < n2) {
    int val1 = L1[ptr1], val2 = L2[ptr2];
    if (val1 > val2) {
      L[ptr++] = val2;
      ptr2++;
    } else {
      L[ptr++] = val1;
      ptr1++;
    }
  }

  while (ptr1 < n1)
    L[ptr++] = L1[ptr1++];

  while (ptr2 < n2)
    L[ptr++] = L2[ptr2++];

  return L;
}

inline void mergesort(int L[], size_t n) {
  if (n > 1) {
    size_t m = n / 2;

    int *L1 = (int *)malloc(m * sizeof(int));
    int *L2 = (int *)malloc((n - m) * sizeof(int));

    memcpy(L1, L, m * sizeof(int));
    memcpy(L2, L + m, (n - m) * sizeof(int));

    mergesort(L1, m);
    mergesort(L2, n - m);

    int *merged = merge(L1, m, L2, n - m);
    memcpy(L, merged, n * sizeof(int));

    free(L1);
    free(L2);
    free(merged);
  }
}
