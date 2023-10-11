#include <stdio.h>
#include <string.h>

enum boolean { false, true };

int main() {
  char s1[100];
  printf("Enter the first word: ");
  scanf("%s", s1);
  int flag = true;
  int left = 0, right = strlen(s1) - 1;

  for (; left != right; left++, right--) {
    if (s1[left] == s1[right])
      flag = true;
    else {
      flag = false;
      break;
    }
  }

  printf("%d\n", flag);

  return 0;
}
