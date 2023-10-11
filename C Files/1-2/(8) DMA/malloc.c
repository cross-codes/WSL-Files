#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int main() {
  short *p1;
  int *p2;
  float *p3;
  int *p4;

  p1 = (short *)malloc(sizeof(short));
  p2 = (int *)malloc(6000 * sizeof(int));
  p3 = (float *)malloc(sizeof(float));
  p4 = (int *)calloc(4, sizeof(int));

  *p1 = 256;
  *p3 = 123.456;

  printf("p1 is %hd\n", *p1);
  printf("p2 is %d\n", *p2);
  printf("p3 is %f\n", *p3);
  printf("sizeof(p2) is %lu", sizeof(p2));
  printf("sizeof(p4) is %lu", sizeof(p4));

  return 0;
}
