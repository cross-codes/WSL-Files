#include <stdio.h>

// Copy the string t to the end of string s
void stringcat(char *s, char *t);

int main() {
  char s[200] = "This is a string. ";
  char t[200] = "This string was appended by stringcat.";

  stringcat(s, t);

  printf("The value of s is now: %s\n", s);

  return 0;
}

void stringcat(char *s, char *t) {
  while (*s != '\0')
    s++;
  while (*t != '\0') {
    *s = *t;
    s++;
    t++;
  }
}
