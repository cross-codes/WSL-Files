#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
  char s1[5] = {'A', 'B', 'z', 'o', 'p'};
  char s2[8] = {'z', 'c', 'a', 'w', '9', 'q', 'b', 'l'};

  printf("Answer: %d", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int ans = -1;
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
      ;
    if (s2[j] == s1[i]) {
      ans = i;
      return ans;
    }
  }

  return ans;
}
