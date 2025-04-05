#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *handle = fopen("f1.txt", "r");
  FILE *write = fopen("file2.txt", "w");

  if (handle == NULL)
  {
    perror("Input file not found\n");
    __builtin_trap();
  }

  size_t n;
  fscanf(handle, "%zd ", &n);
  char buf[20001];
  while (n-- > 0)
  {
    fgets(buf, sizeof(buf), handle);
    char *tokens = strtok(buf, " ");
    while (tokens != NULL)
    {
      fprintf(write, "%d ", atoi(tokens));
      tokens = strtok(NULL, " ");
    }

    fprintf(write, "\n");
  }

  return 0;
}
