#include <stdio.h>

void generate_pattern(int rows);

int main() {
  int rows;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  generate_pattern(rows);

  return 0;
}

void generate_pattern(int rows) {
  int rowcount = 1;
  int fspace = 0, midspace = 0;

  for (; rowcount <= rows; rowcount++) {
    int curr_num = 1;
    if (rowcount == 1) {
      for (int i = 1; i <= rows * 2 - 1; i++) {
        printf("%d ", curr_num);
        curr_num++;
      }
      curr_num = 1;
      printf("\n");
    } else {
      fspace = (rowcount - 1) * 2;
      for (int j = 1; j <= fspace; j++)
        printf(" ");
      midspace = (rows - rowcount) * 4 - 1;
      printf("1");
      for (int k = 1; k <= midspace; k++) {
        printf(" ");
      }
      curr_num = curr_num + (rows - rowcount) * 2;
      (rowcount == rows) ? 0 : printf("%d", curr_num);
      printf("\n");
    }
  }
}
