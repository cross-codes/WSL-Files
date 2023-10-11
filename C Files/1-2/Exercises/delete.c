#include <stdio.h>

void delete_elem(int *v, int element);
int find_elem(int *v, int element);

int main() {
  int arr[10] = {0, 1, 4, 9, 10, 16, 25, -1, -1, -1};
  delete_elem(arr, 9);
  for (int i = 0; i <= 9; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}

void delete_elem(int v[], int e) {
  int i = find_elem(v, e);
  for (; v[i + 1] != -1; i++) {
    v[i] = v[i + 1];
    v[i + 1] = -1;
  }
}

int find_elem(int v[], int e) {
  for (int i = 0; i < 10; i++)
    if (v[i] == e)
      return i;
  return -1;
}
