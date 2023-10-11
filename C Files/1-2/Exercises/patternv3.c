#include <stdio.h>

void pattern_generator(int rows);

int main() {
  int n;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  pattern_generator(n);

  return 0;
}

void pattern_generator(int rows) {
  int rowcount = 1;
  int curr_num = 1;

  for (; rowcount <= rows; rowcount++) {
    int i = 1;
    while (i <= rowcount) {
      printf("%d ", curr_num);
      curr_num++;
      i++;
    }
    printf("\n");
  }
}
