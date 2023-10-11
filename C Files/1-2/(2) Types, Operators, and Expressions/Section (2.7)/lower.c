#include <ctype.h>
#include <stdio.h>

// Two methods for returning a lower case character's value.
int lower(int c);

int main() {
  int c;

  printf("Enter a character: ");
  c = getchar();

  printf("Returned output via function lower: %c\n", lower(c));
  printf("Returned output via standard library function: %c\n", tolower(c));

  return 0;
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return 0;
}
