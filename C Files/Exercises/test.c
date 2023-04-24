#include <stdio.h>

int main() {
  int a = 1, b = 4, c = 3, max;

  max = (a >= b) ? ((a >= c) ? a : c) : ((b >= c) ? b : c);

  printf("%d\n", max);

  int number = 2;

  switch (number) {
  case 1:
  case 2:
  case 3:
    printf("One, Two or Three\n");
  case 4:
  case 5:
  case 6:
    printf("Four, Five or Six\n");
    break;
  default:
    printf("Greater than six\n");
  }

  int rows;

  printf("Enter rows: ");
  scanf("%d", &rows);

  int starcount, spccount = 0;
  int count = rows, star = 0, spc;
  while (count >= 1) {
    spc = spccount;
    while (spc > 0) {
      printf(" ");
      spc--;
    }
    starcount = 2 * count - 1;
    while (star < starcount) {
      printf("*");
      star++;
    }
    count--;
    star = 0;
    spccount++;
    printf("\n");
  }

  return 0;
}
