#include <stdio.h>

#define YES 1
#define NO 0

int checkPrime(int n);

int main() {
  int n;
  printf("Enter the value of the number: ");
  scanf("%d", &n);

  int primes[n];
  int count = 0;

  for (int i = 2, j = 0; i < n; i++, j++) {
    if (checkPrime(i) == YES) {
      primes[j] = i;
      count += 1;
    } else
      j--;
  }

  for (int i = 0; i <= count; i++) {
    for (int j = 0; j <= count; j++) {
      if (n == primes[i] + primes[j]) {
        printf("The number can be expressed as a sum of two primes %d and %d\n",
               primes[i], primes[j]);
        return 0;
      }
    }
  }

  printf("The number cannot be expressed as a sum of primes\n");

  return 0;
}

int checkPrime(int n) {
  int ans = YES;
  if (n == 2)
    return ans;
  for (int i = 2; i < n; i++)
    if (n % i == 0) {
      ans = NO;
      break;
    }

  return ans;
}
