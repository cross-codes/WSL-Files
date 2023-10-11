#include <stdio.h>

void pattern_generator(int rows);

int main() {
  int rows;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  pattern_generator(rows);

  return 0;
}

void pattern_generator(int rows) {
  int stars, spaces;

  for (int rowcount = 1; rowcount < rows; rowcount++) {
    stars = (rows - rowcount) * 2 - 1;
    spaces = rowcount - 1;
    int i = 0, j = 0;

    while (j < spaces) {
      printf("  ");
      j++;
    }

    while (i < stars) {
      printf("* ");
      i++;
    }
    printf("\n");
  }
}
