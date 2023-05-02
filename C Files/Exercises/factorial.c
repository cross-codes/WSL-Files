#include <stdio.h>

int factn(int n);

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);
  int ans = factn(n);

  if (ans == -1)
    printf("Factorial is not defined\n");
  else
    printf("The value of %d! is: %d\n", n, ans);

  return 0;
}

int factn(int n) {
  int i = n, ans = 1;

  if (n < 0)
    return -1;

  while (i > 0) {
    ans *= i;
    i--;
  }

  return ans;
}
