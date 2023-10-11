#include <stdio.h>

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *pa;
  int *pb;

  pb = a;

  pa = &a[0];

  printf("The second element of the array is: %d\n", *(pa + 1));
  printf("The value of the first element of the array is: %d or %d\n", *pb, *a);
  printf("Is a[i] = *(a+i)?: %d\n", (a[1] == *(a + 1)));
  return 0;
}
