#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

int main() {
  FILE *fp;
  fp = fopen("itself.c", "r");
  char code[10000];
  char line[1000];
  while (fgets(line, 999, fp) != NULL)
    strncat(code, line, strlen(line));
  fputs(code, stdout);
  return 0;
}
