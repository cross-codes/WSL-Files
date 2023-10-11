#include <stdio.h>

int main() {
  int n;

  printf("Enter your number: ");
  scanf("%d", &n);

  (n % 11 == 0) ? (printf("This number is a palindrome\n"))
                : printf("This number is not a palindrome\n");

  return 0;
}
