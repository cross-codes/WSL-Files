#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int main() {
  short *p1;
  int *p2;
  float *p3;

  p1 = (short *)malloc(sizeof(short));
  p2 = (int *)malloc(sizeof(int));
  p3 = (float *)malloc(sizeof(float));

  *p1 = 256;
  *p2 = 100;
  *p3 = 123.456;

  printf("p1 is %hd\n", *p1);
  printf("p2 is %d\n", *p2);
  printf("p3 is %f\n", *p3);

  return 0;
}
