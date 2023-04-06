#include <stdio.h>
#define MAXVAL 100

int pop(int array[]);
int push(int array[], int element);
int view(int array[]);

int top = -1;
int stk[MAXVAL];

int main() {
  printf("%d\n", pop(stk));
  push(stk, 1);
  printf("%d\n", view(stk));
  printf("%d\n", pop(stk));
  printf("%d\n", pop(stk));
  printf("%d\n", view(stk));

  return 0;
}

int pop(int arr[]) {
  if (top == -1) {
    printf("Underflow error: ");
    return -1;
  } else if (top > 0)
    return arr[top--];
  else {
    top = -1;
    return arr[0];
  }
}

int push(int arr[], int e) {
  if (top >= MAXVAL) {
    printf("Overflow error: ");
    return -1;
  } else {
    arr[++top] = e;
    return 0;
  }
}

int view(int arr[]) {
  if (top >= MAXVAL) {
    printf("Overflow error: ");
    return -1;
  } else if (top == -1) {
    printf("Underflow error: ");
    return -1;
  } else {
    return arr[top];
  }
}
