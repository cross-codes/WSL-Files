#include <stdio.h>
#include <string.h>

void reverse(char s[], int index);

int main() {
  char str1[] = "esrever";
  char str2[] = "tna";
  int i = 0;

  reverse(str1, 0);
  for (; i < 9; ++i)
    printf("%c\n", str1[i]);
  reverse(str2, 0);
  for (i = 0; i < 3; ++i)
    printf("%c\n", str2[i]);
  return 0;
}

void reverse(char s[], int i) {
  int j = i;
  char temp1, temp2;

  temp1 = s[j];
  temp2 = s[strlen(s) - j - 1];
  s[j] = temp2;
  s[strlen(s) - j - 1] = temp1;

  if (j + 1 < strlen(s) / 2)
    reverse(s, ++j);
}
