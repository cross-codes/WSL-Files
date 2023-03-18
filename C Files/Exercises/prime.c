#include <stdio.h>

#define YES 1
#define NO 0

int main() {
  int num;
  int n = 2;
  int prime = YES;
  printf("Enter the number: ");
  scanf("%d", &num);

  for (; n <= num / 2; ++n) {
    if (num % n == 0) {
      prime = NO;
      break;
    } else {
      prime = YES;
    }
  }

  if (prime == NO) {
    printf("Not a prime number\n");
  } else
    printf("Input number is a prime number!\n");

  return 0;
}
