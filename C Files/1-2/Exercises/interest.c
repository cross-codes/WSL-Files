/* Write a C program to enter Principal (P), Time (T), Rate of Interest (R) and
calculate Simple Interest (SI) and show it to the user. Note that SI = PxRxT.*/
#include <stdio.h>

int main() {
  double p, t, r, si;

  printf("Enter the principal amount (INR): ");
  scanf("%lf", &p);

  printf("Enter the time interval (days): ");
  scanf("%lf", &t);

  printf("Enter the principal amount (/day): ");
  scanf("%lf", &r);

  si = p * t * r;

  printf("The simple interest is %lf\n", si);

  return 0;
}
