#include <stdio.h>

void escape(char final[], char initial[]);

int main() {
  char t[] = "This is a tab space   ";
  char s[200];

  escape(s, t);
  printf("%s\n %s\n", s, t);
  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++)
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  s[j] = '\0';
}
/*$$r_n = \frac{n^2}{Z} a_0 \text{   and }
 * E_n=-\frac{k_ee^2}{2a_0}.(\frac{Z^2}{n^2})$$*/
