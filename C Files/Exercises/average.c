#include <stdio.h>

int main() {
  int a, b, c;
  float avg;

  printf("Enter the first number: ");
  scanf("%d", &a);
  printf("Enter the second number: ");
  scanf("%d", &b);
  printf("Enter the third number: ");
  scanf("%d", &c);

  avg = (a + b + c) / 3.0;
  printf("The average of the three numbers is: %f\n", avg);

  return 0;
}
