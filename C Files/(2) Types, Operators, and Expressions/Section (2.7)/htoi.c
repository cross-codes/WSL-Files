#include <stdio.h>
#include <string.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main() {
  char string[] = "0x8bc3";

  printf("The integer value is : %d\n", htoi(string));

  return 0;
}

int htoi(char s[]) {
  int ans, i;
  ans = 0;
  i = 0;
  int valid = YES;
  int hexdigit;
  int len = strlen(s);

  if (s[i] == '0')
    ++i;
  if ((s[i] == 'x') || (s[i] == 'X'))
    ++i;

  for (; valid == YES && i < len; ++i) {
    if (s[i] >= 'a' && s[i] <= 'f')
      hexdigit = s[i] - 'a' + 10;
    else if (s[i] >= '0' && s[i] <= '9')
      hexdigit = s[i] - '0';
    else if (s[i] >= 'A' && s[i] <= 'F')
      hexdigit = s[i] - 'A' + 10;
    else
      valid = NO;

    if (valid == YES)
      ans = 16 * ans + hexdigit;
  }

  if (valid == YES)
    return ans;

  else
    return 0;
}
