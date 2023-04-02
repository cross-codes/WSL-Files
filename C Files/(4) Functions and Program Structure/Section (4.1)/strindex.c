#include <stdio.h>
#include <string.h>

void reverse(char string[]);
int strindex(char source[], char string[]);

int main() {
  int found;
  char source[] = "This is an occurence is of sorts";
  char string[] = "is";

  printf("The rightmost occurence is at index %d\n",
         found = strindex(source, string));

  return found;
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int strindex(char s[], char t[]) {
  int i, j, k;
  reverse(s);
  reverse(t);

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return (strlen(s) - i - 1);
  }
  return -1;
}
