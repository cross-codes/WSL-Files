#include <math.h>
#include <stdio.h>

int main() {
  int a, b, c;
  double D, s, r;

  printf("Quadratic equation solver: ax²+ bx + c = 0\n");
  printf("Enter a value for a: ");
  scanf("%d", &a);
  printf("Enter a value for b: ");
  scanf("%d", &b);
  printf("Enter a value for c: ");
  scanf("%d", &c);

  printf("The equation is %dx²+ %dx + %d = 0\n", a, b, c);

  D = (b * b) - (4 * a * c);
  if (a == 0 && b == 0 && c == 0)
    printf("Infinitely many solutions!\n");
  else if (a == 0)
    printf("Not a quadratic equation!\n");
  else if (D >= 0) {
    s = (-b + sqrt(D)) / (2 * a);
    r = (-b - sqrt(D)) / (2 * a);

    printf("The roots are: %lf and %lf\n", s, r);
  } else
    printf("The roots are imaginary\n");

  return 0;
}
