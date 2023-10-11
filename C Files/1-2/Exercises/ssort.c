#include <limits.h>
#include <stdio.h>

void ssort(int v[], int length);
int minfind(int x[], int start, int length);

int main() {
  int arr[] = {14, 33, 27, 10, 35, 19, 42, 44};

  ssort(arr, 8);

  for (int i = 0; i < 8; i++)
    printf("%d, ", arr[i]);

  printf("\n");
  return 0;
}

void ssort(int v[], int l) {
  int i = 0, j = 0, temp = 0, min_index = 0;
  for (; i < l; i++) {
    min_index = minfind(v, i, l);
    temp = v[i];
    v[i] = v[min_index];
    v[min_index] = temp;
  }
}

int minfind(int v[], int s, int l) {
  int j = INT_MAX, ans = 0;
  for (int i = s; i < l; i++)
    if (v[i] < j) {
      ans = i;
      j = v[i];
    }
  return ans;
}
