#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
  int m, d;
  printf("The corresponding number of days is: %d\n", day_of_year(2004, 3, 22));
  month_day(2004, 98, &m, &d);
  printf(
      "The month and day from the corresponding number of days is: %d and %d\n",
      m, d);
  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 ||
         year % 400 == 0; // leap is either 1 or 0
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
