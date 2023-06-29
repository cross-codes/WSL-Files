#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int main() {
  FILE *fp;
  char foo_str[80], std_str[80];
  fputs("Enter a line: \n", stdout);
  fgets(std_str, 79, stdin);
  fp = fopen("foo.txt", "a+");
  fputs(std_str, fp);
  rewind(fp);
  fgets(foo_str, 79, fp);
  printf("\n");
  fputs(foo_str, stdout);
  fclose(fp);
  return 0;
}
