#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

struct point makepoint(int x, int y);

int main() {
  struct rect screen;
  struct point middle;
  struct point makepoint(int, int);
  return 0;
}

struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}
