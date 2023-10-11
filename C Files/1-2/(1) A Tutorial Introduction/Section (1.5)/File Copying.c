#include <stdio.h>
/*getchar() reads the next input character from an input stream and returns that
as its value putchar() prints a character each time it is called. For example,
putchar(c) prints the contents of an integer variable c as a character*/
/* Equivalent code:
    int d;
    while ((d = getchar()) != EOF) {
        putchar(d);
        printf("\n")
    }
*/

main() {
  int c; /*This datatype is big enough to store the End Of File character*/
  c = getchar();
  while (c != EOF) { /*EOF = ctrl + d*/
    putchar(c);
    c = getchar();
  }
}
