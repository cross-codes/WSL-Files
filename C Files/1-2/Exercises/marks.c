#include <stdio.h>

int main() {
  int grade;

  printf("Enter the marks scored: ");
  scanf("%d", &grade);

  if (grade > 100)
    printf("This is an example of wishful thinking\n");
  else if (grade > 90)
    printf("Your grade is: A\n");
  else if (grade > 80)
    printf("Your grade is: B\n");
  else if (grade > 70)
    printf("Your grade is: C\n");
  else
    printf("You have failed loser\n");
  return 0;
}
