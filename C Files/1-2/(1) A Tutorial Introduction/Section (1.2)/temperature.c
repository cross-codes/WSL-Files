#include <stdio.h>
/* The first part of the code is the solution to exercise (1.3) (Farenheit to
Celsius). The second part is the solution to exercise (1.4)*/

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Converting Farenheit to Celsius\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius); /*Each % construction is paired with
                                               the corresponding argument*/
    fahr = fahr + step;
  }

  celsius = lower;
  printf("\nConverting Celsius to Farenheit\n");
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32;
    printf("%3.0f %6.1f\n", celsius, fahr); /*%6.1f -> A float number atleast 6
                                               spaces wide and 1 decimal point*/
    celsius = celsius + step;
  }
}
