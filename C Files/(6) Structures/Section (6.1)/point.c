#include <stdio.h>

int main() {
  struct point {
    int x;
    int y;
  } a, b, c;

  struct point maxpt = {320, 200};

  printf("%d, %d\n", maxpt.x, maxpt.y);

  struct point pt;
  pt.x = 10;
  pt.y = 20;

  printf("%d, %d\n", pt.x, pt.y);

  struct rect {
    struct point pt1;

    struct point pt2;
  };

  struct cmplx {
    int real;
    int cmplx;
  } d;
  d.real = 2;
  d.cmplx = 3;

  struct cmplx e;

  e.real = 3;
  e.cmplx = 4;

  struct cmplx f;

  f.real = d.real + e.real;
  f.cmplx = d.cmplx + e.cmplx;

  printf("%d + i%d + %d + i%d = %d + i%d\n", d.real, d.cmplx, e.real, e.cmplx,
         f.real, f.cmplx);
  return 0;
}
