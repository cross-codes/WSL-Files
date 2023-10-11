#include <stdio.h>

char *month_name(int n);
int main() {
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  printf("%s\n", month_name(n));
  printf("%p\n", month_name(n));

  return 0;
}

char *month_name(int n) {
  static char *name[] = {"Illegal month", "January",   "February", "March",
                         "April",         "May",       "June",     "July",
                         "August",        "September", "October",  "November",
                         "December"};

  return (n < 1 || n > 12) ? name[0] : name[n];
}
