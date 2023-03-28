#include <stdio.h>
#include <string.h>

void reverse(char string[]);

int main() {
  char string[] = "This is a string lolmao";
  int i;

  reverse(string);

  for (i = 0; (string[i] != '\0'); ++i)
    printf("%c ", string[i]);
  printf("\n");

  return 0;
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
