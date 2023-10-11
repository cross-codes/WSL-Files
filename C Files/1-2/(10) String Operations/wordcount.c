#include <ctype.h>
#include <stdio.h>
#pragma pack(1)

int main() {
  char s1[100];
  printf("Enter a sentence: ");
  scanf("%[^\n]s", s1);

  int nw = 0;
  int word_start = 0;
  for (int i = 0; s1[i] != '\0'; i++) {
    if (!word_start) {
      if (!isspace(s1[i])) {
        word_start = 1;
        continue;
      }
      continue;
    }
    if (isspace(s1[i])) {
      nw++;
      printf("%d", nw);
    }
  }
  nw++;

  printf("The number of words were: %d\n", nw);
  return 0;
}
