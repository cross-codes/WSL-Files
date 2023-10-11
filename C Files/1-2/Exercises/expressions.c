#include <math.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

/*The expressions are:
$\frac{e^x . sin(60) + (5.6 x 10^(-5))}{3 . cos(30)}$
$sin(\frac{arctan(0.33) + \pi}{2y}$
*/

int main() {
  float x, y, expr1, expr2;

  printf("Enter the value of x: ");
  scanf("%f", &x);
  printf("Enter the value of y: ");
  scanf("%f", &y);

  expr1 = ((exp(x) * sin(M_PI * 60 / 180)) + (5.6 * pow(10.0, -5.0))) /
          (3 * cos(M_PI * 30 / 180));
  expr2 = sin(((atan(0.33) + (M_PI)) / (2 * y)) * M_PI / 180);

  printf("The value of expr1 and expr2 are respectively: %.3f and %.3f\n",
         expr1, expr2);

  return EXIT_SUCCESS;
}
