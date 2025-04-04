#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma pack(1)

int64_t iterativeFibonnaci(int32_t);
int64_t recursiveFibonnaci(int32_t);

int32_t main(int argc, char **argv) {

  clock_t start = clock();
  int64_t iter = iterativeFibonnaci(100);
  clock_t end = clock();

  printf("Iterative fibonnaci: %lf s\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  int64_t recur = recursiveFibonnaci(100);
  end = clock();

  printf("Recursive fibonnaci: %lf s\n",
         (double)(end - start) / CLOCKS_PER_SEC);

  printf("Iterative Result: %ld, Recursive result: %ld\n", iter, recur);

  return 0;
}

int64_t iterativeFibonnaci(int32_t n) {
  if (n < 2) {
    return n;
  } else {
    int64_t before = 1, prior = 1, current;
    for (size_t i = 3; i <= n; i++) {
      current = before + prior;
      prior = before, before = current;
    }

    return current;
  }
}

int64_t recursiveFibonnaci(int32_t n) {
  if (n < 2)
    return n;

  return recursiveFibonnaci(n - 1) + recursiveFibonnaci(n - 2);
}
