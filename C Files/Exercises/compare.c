#include <stdio.h>

int main() {
  int x, ans;
  double y, z;

  printf("Enter a number: ");
  scanf("%lf", &y);
  x = y;
  z = y - x;
  printf("x = %d, y = %.24lf, z = %.24lf\n", x, y, z);

  if (z < 0.6)
    ans = y;
  else
    ans = y + 1;

  printf("Round off: %d\n", ans);

  double c, d, sum;
  c = 0.1;
  d = 0.2;
  sum = c + d;
  printf("Sum: %.24lf\n", sum);
  return 0;
}
