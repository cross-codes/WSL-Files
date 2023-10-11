#include <stdio.h>

int fib_term(int n);

int main() {
  int n;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    printf("%d ", fib_term(i));

  printf("\n");
  return 0;
}

int fib_term(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib_term(n - 1) + fib_term(n - 2);
}
