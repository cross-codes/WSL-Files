#include <stdio.h>

void factsum(int n);
int factorial(int n);

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  factsum(n);

  return 0;
}

void factsum(int n) {
  int i = 1;
  int sum = 0;
  for (; i <= n; i++) {
    int temp = factorial(i) / i;
    sum += temp;
  }

  printf("The final sum is: %d\n", sum);
}

int factorial(int n) {
  int i = 1, ans = 1;
  for (; i <= n; i++) {
    ans *= i;
  }

  return ans;
}
