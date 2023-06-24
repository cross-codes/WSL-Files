#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

enum boolean { false, true };

int isArmstrong(int n);
int power(int x, int y);

int main() {
  int a;
  printf("Enter a number: ");
  scanf("%d", &a);
  isArmstrong(a) ? printf("The number is an armstrong number\n")
                 : printf("The number is not an armstrong number\n");

  return 0;
}

int isArmstrong(int n) {
  int count = 0;
  int temp = n;
  int sum = 0;
  for (; temp != 0; count++)
    temp /= 10;
  temp = n;
  for (int i = 0; i < count; i++, temp /= 10)
    sum += power(temp % 10, count);
  return (sum == n) ? true : false;
}

int power(int x, int y) {
  int ans = 1;
  for (int i = 0; i < y; i++)
    ans *= x;

  return ans;
}
