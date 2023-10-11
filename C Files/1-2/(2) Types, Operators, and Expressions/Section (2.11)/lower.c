#include <stdio.h>

char lower(char s);

int main() {
  char s = 'Q';
  char s_mod;

  s_mod = lower(s);
  printf("%c\n", s_mod);

  return 0;
}

char lower(char s) { return (s > 'A' && s < 'Z') ? s + 'a' - 'A' : s; }
