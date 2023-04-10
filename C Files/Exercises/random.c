#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n;
  n = 5;

  // Initializes ranodm number generator
  srand(time(0));

  // Print 5 ranodm numbers from 0 to 49
  for (i = 0; i < n; ++i)
    printf("%d\n", rand() % 50);

  return 0;
}
