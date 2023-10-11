#include <stdio.h>

int stringlen(char *s);

int main() {
  char t[] = "This is a test";

  printf("The length of t is: %d\n", stringlen(t));

  return 0;
}

int stringlen(char *s) {
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;

  return n;
}
