#include <sys/types.h>

#include "intMergeAux.h"

void mergeAux(int L1[], ssize_t start1, ssize_t end1, int L2[], ssize_t start2,
              ssize_t end2, int L3[], ssize_t start3, ssize_t end3) {
  int i = start1, j = start2, k = start3;

  while (i <= end1 && j <= end2) {
    if (L1[i] < L2[j])
      L3[k++] = L1[i++];
    else
      L3[k++] = L2[j++];
  }

  while (i <= end1)
    L3[k++] = L1[i++];

  while (j <= end2)
    L3[k++] = L2[j++];
}
