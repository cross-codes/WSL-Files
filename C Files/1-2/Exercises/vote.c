#include <stdio.h>

int main() {
  int age, valid;

  printf("Enter your age: ");
  scanf("%d", &age);

  valid =
      (age >= 18) ? (printf("You can vote\n")) : printf("You cannot vote\n");
  return 0;
}
