#include <stdio.h>

int main() {
  int n;

  printf("Enter a value for n: ");
  scanf("%d", &n);

  if (n >= 0) {
    int i = n;
    int sum = 0;

    for (; i <= 2 * n; i++)
      sum += i;
    printf("The result is: %d\n", sum);
  } else {
    int i = 3 * n;
    int sum = 0;

    for (; i <= 2 * n; i++)
      sum += i;
    printf("The result is: %d\n", sum);
  }

  return 0;
}
