#include <math.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

/* Write a C program to enter P, T, R and calculate Compound Interest and show
it to the user. Hint: A = P(1+(R/100))^t A = final amount P = initial principal
balance R = interest rate t = number of years */

int main() {
  double p, t, r, A;

  printf("Enter the value of the principle amount (INR): ");
  scanf("%lf", &p);
  printf("Enter the value of the time period (months): ");
  scanf("%lf", &t);
  printf("Enter the value of the interest rate (INR/month): ");
  scanf("%lf", &r);

  A = p * pow((1 + (r / 100)), t);

  printf(
      "The final amount with compound interest taken into account is: %.3lf\n",
      A);

  return EXIT_SUCCESS;
}
