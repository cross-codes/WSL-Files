#include <stdio.h>
/*Exercise 1.8*/
#define NOTBLANK 'A'
main() {

  int c, tabs, blanks, newlines;

  tabs = 0;
  blanks = 0;
  newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t')
      ++tabs;
    if (c == '\n')
      ++newlines;
    if (c == ' ')
      ++blanks;
  }
  printf("\n Number of blanks: %d", blanks);
  printf("\n Number of newlines: %d", newlines);
  printf("\n Number of tabs: %d\n", tabs);

  /*Exercise (1.9)
  To execute, comment out the rest of the code.*/

  int d, lastchar;
  lastchar = NOTBLANK;

  while ((d = getchar()) != EOF) {
    if (d != ' ')
      putchar(d);
    if (d == ' ') {
      if (lastchar != ' ')
        putchar(d);
      lastchar = d;
    }
  }

  /*Exercise (1.10)
  To execute, comment out the rest of the code.*/
  int e;

  while ((e = getchar()) != EOF) {
    if (e == '\t')
      printf("\\t");
    if (e == '\b')
      printf("\\b");
    if (e == '\\')
      printf("\\\\");
    else
      putchar(e);
  }
}
