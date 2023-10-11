#include <stdio.h>

/*
Write a C program that reads in an integer denoting number of days. It prints
the number of years, number of months and the number of days that constitute the
input number of days. For example, if the input number is 403, it should print
1(year), 1(month), 13(days). For simplicity: there is no need to consider leap
years and assume all months have 30 days.
*/

int main() {
  int days, months, years;
  int input;

  printf("Enter the number of days: ");
  scanf("%d", &input);

  years = input / 360;
  printf("%d\n", years);
  months = (input - (years * 360)) / 30;
  days = input - (years * 360) - (months * 30);

  printf("%d(year), %d(month), %d(days)\n", years, months, days);

  return 0;
}
