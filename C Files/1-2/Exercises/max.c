#include <stdio.h>

int main() {
  int a, b, c;

  printf("Enter the value of a: ");
  scanf("%d", &a);
  printf("Enter the value of b: ");
  scanf("%d", &b);
  printf("Enter the value of c: ");
  scanf("%d", &c);

  int max = (a >= b) ? ((a >= c) ? a : c) : ((b >= c) ? b : c);

  printf("The maximum among these numbers is %d\n", max);
  return 0;
}
