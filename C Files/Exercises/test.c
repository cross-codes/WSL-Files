#include <stdio.h>

void test() {
  int c;
  printf("c: %d\n", c);

}

int main() {
  int a;
  static int i = 0;

  {
    int b;
    printf("b: %d\n", b);
  }

  printf("a: %d\n", a);
  test();
  return 0;
}
