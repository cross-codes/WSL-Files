#include <stdio.h>

/* Program to reverse a line, per line*/
#define MAXLENGTH 100 /* Maximum line length */

void reverse(char line[]);
int getlines(char line[], int max_length);

main() {
  int len;              /* Length of the line */
  char line[MAXLENGTH]; /* The line itself */

  while ((len = getlines(line, MAXLENGTH)) > 0) {
    reverse(line);
    printf("%s\n", line);
  }

  return 0;
}

int getlines(char s[], int max_length) {
  int c, i;

  for (i = 0; i < (MAXLENGTH - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c = '\n')
    s[i] = c;
  ++i;
  s[i] = '\0';
  return i;
}

void reverse(char s[]) {
  int i, j;
  char temp;

  i = 0;
  while (s[i] != '\0')
    ++i;
  --i;
  if (s[i] == '\n')
    --i;

  j = 0;
  while (j < i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    --i;
    ++j;
  }
}
