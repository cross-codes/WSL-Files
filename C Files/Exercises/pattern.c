#include <stdio.h>

#define EXIT_SUCCESS 0

int main() {
  int rows, curr, num, minnum, maxnum, spc_count, spc;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  curr = 1;
  spc_count = (rows * 2) - 2;

  while (curr <= rows) {
    minnum = curr;
    num = minnum;
    spc = 0;
    maxnum = num + curr - 1;
    while (spc <= spc_count) {
      printf(" ");
      spc++;
    }
    while (num <= maxnum) {
      printf("%d ", num);
      num++;
    }
    num--;
    while (num > minnum) {
      num--;
      printf("%d ", num);
    }
    printf("\n");
    curr++;
    spc_count -= 2;
  }

  return EXIT_SUCCESS;
}
