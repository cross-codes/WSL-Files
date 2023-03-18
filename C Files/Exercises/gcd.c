#include <stdio.h>

int main() {
  int n1, n2, i;
  int gcd = 1;
  int smaller, bigger;

  printf("Enter the first number: ");
  scanf("%d", &n1);
  printf("Enter the second number: ");
  scanf("%d", &n2);
  smaller = (n1 > n2) ? n2 : n1;
  bigger = (n1 > n2) ? n1 : n2;
  for (i = smaller; i <= smaller; --i) {
    if ((smaller % i) == 0 && (bigger % i == 0)) {
      gcd = i;
      break;
    }
  }

  printf("The GCD of %d and %d is : %d\n", n1, n2, gcd);

  return 0;
}
