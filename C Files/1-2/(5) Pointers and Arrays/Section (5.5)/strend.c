#include <stdio.h>

int strend(char *s, char *t);

int main() {
  char s[200] = "This is a string.";
  char t[200] = "is a string.";
  char u[200] = "si a string.";

  printf("Among s and u: %d\n", strend(s, u));
  return 0;
}

int strend(char *s, char *t) {

  int len1 = 0, len2 = 0;
  char *temp1 = s;
  char *temp2 = t;

  while (*temp1 != '\0') {
    len1++;
    temp1++;
  }
  while (*temp2 != '\0') {
    len2++;
    temp2++;
  }

  s += len1 - 1;
  t += len2 - 1;

  while (*s == *t) {
    s--;
    t--;

    if ((*t == *s) && (*t == *(temp2 - len2)))
      return 1;
  }
  return 0;
}
