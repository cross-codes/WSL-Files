#include <stdio.h>

/* Program to convert a string constant to an integer */
int atoi(char string[]);

int main() {
  char s[5] = {'9', '6', '7', '1', '2'};
  printf("%d\n", atoi(s));
}

int atoi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}
