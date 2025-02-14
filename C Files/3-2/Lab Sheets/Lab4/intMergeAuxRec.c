#include <sys/types.h>

#include "intMergeAux.h"

void mergeAux(int L1[], ssize_t start1, ssize_t end1, int L2[], ssize_t start2,
              ssize_t end2, int L3[], ssize_t start3, ssize_t end3) {
  if (start1 > end1 && start2 > end2)
    return;

  if (start1 > end1) {
    L3[start3] = L2[start2];
    mergeAux(L1, start1, end1, L2, start2 + 1, end2, L3, start3 + 1, end3);
  } else if (start2 > end2) {
    L3[start3] = L1[start1];
    mergeAux(L1, start1 + 1, end1, L2, start2, end2, L3, start3 + 1, end3);
  } else if (L1[start1] <= L2[start2]) {
    L3[start3] = L1[start1];
    mergeAux(L1, start1 + 1, end1, L2, start2, end2, L3, start3 + 1, end3);
  } else {
    L3[start3] = L2[start2];
    mergeAux(L1, start1, end1, L2, start2 + 1, end2, L3, start3 + 1, end3);
  }
}
