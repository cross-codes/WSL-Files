#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int main() {
  FILE *fp;
  char toRead[100];
  fp = fopen("data.txt", "r+");
  int sum = 0;
  while (fgets(toRead, 100, fp) != NULL) {
    printf("%s", toRead);
    sum += atoi(toRead);
  }
  char char_sum[50];
  sprintf(char_sum, "%d ", sum);
  fputs(char_sum, stdout);
  printf("\n");
  return 0;
}
