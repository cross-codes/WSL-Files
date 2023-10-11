#include <stdio.h>

int main() {
  int x = 1, y = x;

  switch(--y || x++ -1) {
    case 1: printf("Good");
    default: printf("Day");
    case -1: printf("Night");
  }
  printf("\n x = %d, y = %d", x, y);

  return 0;
}
