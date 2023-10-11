#include <math.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

int main() {
  double x, n, ans;

  printf("Enter the value of the base: ");
  scanf("%lf", &x);

  printf("Enter the value of the exponent: ");
  scanf("%lf", &n);

  ans = pow(x, n);

  printf("The value of %.3lf raised to %.3lf is: %.2lf\n", x, n, ans);

  return EXIT_SUCCESS;
}
