#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int count(int num, int arr[], int size);

int main() {
  printf("Enter a set of 10 numbers: ");
  int stor[10];

  for (int i = 0; i < 10; i++)
    scanf("%d", stor + i);

  printf("The number of times 5 is in the array is: %d", count(5, stor, 10));

  return 0;
}

int count(int num, int arr[], int size) {
  if (size == 0)
    return 0;

  if (arr[size - 1] == num)
    return 1 + count(num, arr, size - 1);
  else
    return count(num, arr, size - 1);
}
