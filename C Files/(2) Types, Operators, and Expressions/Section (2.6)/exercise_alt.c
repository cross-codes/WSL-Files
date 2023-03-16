#include <stdio.h>

int main()
{
  char s[100];
  int i, c;
  int lim = 10;

  enum loop {NO, YES};
  enum loop okloop = YES;

  i = 0;
  while (okloop == YES)
    if (i >= lim - 1)
      okloop = NO;
    else if ((c = getchar()) == '\n')
      okloop = NO;
    else if (c == EOF)
        okloop = NO;
    else {
      s[i] = c;
      ++i;
    }
  
  return 0;
}
