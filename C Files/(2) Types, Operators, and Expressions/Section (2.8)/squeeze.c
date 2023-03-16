#include <stdio.h>
#include <string.h>

// Squeeze modified
void squeeze(char s1[], char s2[]);

int main() {
  char s1[5] = {'a', 'B', 'd', 'e', 'f'};
  char s2[5] = {'b', 'a', 'C', 'f', 'x'};
  int i = 0;

  squeeze(s1, s2);

  for (; s1[i] != '\0'; ++i) {
    printf("%c", s1[i]);
  }
  printf("\n");
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = k = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
      ;
    if (s2[j] == '\0') /* This can only be reached if the match doesn't happen*/
      s1[k++] =
          s1[i]; /* This will replace the positions of any one that matched*/
  }
  s1[k] = '\0';
}
