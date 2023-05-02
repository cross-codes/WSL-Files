#include <stdio.h>

int compute_sum(int n);
long power(int i);

int main() {
  int n;

  printf("Enter a value for n: ");
  scanf("%d", &n);

  if (n >= 0)
    printf("The answer is: %d\n", compute_sum(n));
  else
    printf("The series is not defined for the given value of n\n");

  return 0;
}

int compute_sum(int n) {
  int i = 0, ans = 0;

  while (i <= n - 1) {
    ans += power(i + 1);
    i++;
  }

  return ans;
}

long power(int i) {
  int ans = i;
  int j = 1;

  for (; j < i; j++)
    ans *= i;

  return ans;
}
