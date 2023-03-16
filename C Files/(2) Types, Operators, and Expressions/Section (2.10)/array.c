#include <stdio.h>

int main() {
  char s[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'};
  int i;
  int n = 20;

  for (i = 0; i < n; i++)
    printf("%6d%c", s[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
  return 0;
}
