#include <stdio.h>

void shellsort(float *v, int length);

int main() {
  float arr[10];

  for (int i = 0; i < 10; i++) {
    printf("Enter a number: ");
    scanf("%f", arr + i);
  }
  shellsort(arr, 10);

  float max = arr[9], second_max = arr[8], min = arr[0], second_min = arr[1];
  printf("Maximum: %.2f, Minimum: %.2f, Second maximum: %.2f, Second minimum: "
         "%.2f, "
         "Average: %.2f\n",
         max, min, second_max, second_min,
         (max + min + second_max + second_min) / 4.0);
  return 0;
}

void shellsort(float *v, int n) {
  int gap, i, j;
  float temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}
