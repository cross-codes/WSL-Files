#include <stdio.h>

#define MAXLINE 1000 /* Maximum line size */

int max;               /* Maximum line seen so far */
char line[MAXLINE];    /* Current input line */
char longest[MAXLINE]; /* Longest line here */

int getlines(void);
void copy(void);

/* Print the longest input line (v2) */
int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getlines()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0) /* There was a line */
    printf("%s", longest);
  return 0;
}

int getlines(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
