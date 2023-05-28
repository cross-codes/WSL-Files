#include <stdio.h>
#pragma pack(4)

int main() {
  struct key {
    char *word;
    int count;
  } keytab[] = {
      {"auto", 0},
      {"break", 0},
      {"case", 0},
      {"continue", 0},
  };

  printf("%p\n", keytab[0].word);
  return 0;
}
