#include <stdio.h>

float convert(int fahr) {
  float celsius;

  celsius = (5.0 / 9.0) * (fahr - 32.0);
  return celsius;
}

main() {
  int fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3d %6.1f\n", fahr, convert(fahr));
    fahr = fahr + step;
  }
}
