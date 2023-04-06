#include <stdio.h>

#define MAXVAL 100 // Maximum stack length

double pop(double array[]);
int push(double element, double array[]);
double lst[MAXVAL];
int sp = 0;

int main() {

  lst[0] = 0.0;
  push(5.0, lst);
  printf("%lf\n", lst[0]);
  pop(lst);
  printf("%lf\n", lst[0]);
  pop(lst);

  return 0;
}

int push(double f, double v[]) {
  if (sp < MAXVAL)
    v[sp++] = f;
  else
    printf("Error: Overflow\n");

  return 0;
}

double pop(double v[]) {
  if (sp > 0) {
    return v[--sp];
  } else {
    printf("Error: Stack underflow\n");
    return 0.0;
  }
}
