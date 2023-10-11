#include <limits.h>
#include <stdio.h>

#define true 1
#define false 0
#define MAXVAL 100

int binarySearch(int v[], int x, int length);
int linearSearch(int v[], int x, int length);
void selectionSortDec(int v[], int length);
void generate_arr(int v[], int length);
int find_max(int v[], int start, int end);

int main() {
  int checker = true;
  while (checker) {
    printf("Choose an option among the following:\n"
           "(1) Perform a linear search on an array for a particular element\n"
           "(2) Perform a binary search on an array for a particular element\n"
           "(3) Perform a decreasing selection sort on an array\n"
           "(4) Exit from the program\n");

    int option = 0;
    printf("Option: ");
    scanf("%d", &option);

    if (option == 1) {
      int arr[MAXVAL], length, element;
      printf("Enter the length of the array: ");
      scanf("%d", &length);
      generate_arr(arr, length);
      printf("Enter the number you would like to search for: ");
      scanf("%d", &element);

      int ans = linearSearch(arr, element, length);

      if ((ans < 0) || (ans >= length))
        printf("Element not found\n");
      else
        printf("The element %d is at index position %d\n", element, ans);

      char choice = 'N';
      printf("Would you like to go again (y/N): ");
      scanf(" %c", &choice);

      if (choice == 'y') {
        checker = true;
        continue;
      } else if (choice == 'N') {
        checker = false;
        break;
      } else {
        printf("Invalid input, quitting\n");
        checker = false;
        break;
      }
    } else if (option == 2) {
      int arr[MAXVAL], length, element;
      printf("Enter the length of the array: ");
      scanf("%d", &length);
      generate_arr(arr, length);
      printf("Enter the number you would like to search for: ");
      scanf("%d", &element);

      selectionSortDec(arr, length);

      int ans = binarySearch(arr, element, length);

      if ((ans < 0) || (ans >= length))
        printf("Element not found\n");
      else
        printf("The element %d is at index position %d\n", element, ans);

      char choice = 'N';
      printf("Would you like to go again (y/N): ");
      scanf(" %c", &choice);

      if (choice == 'y') {
        checker = true;
        continue;
      } else if (choice == 'N') {
        checker = false;
        break;
      } else {
        printf("Invalid input, quitting\n");
        checker = false;
        break;
      }
    } else if (option == 3) {
      int arr[MAXVAL], length, element;
      printf("Enter the length of the array: ");
      scanf("%d", &length);
      generate_arr(arr, length);

      selectionSortDec(arr, length);

      printf("The elements of the array are: \n");

      for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

      char choice = 'N';
      printf("\nWould you like to go again (y/N): ");
      scanf(" %c", &choice);

      if (choice == 'y') {
        checker = true;
        continue;
      } else if (choice == 'N') {
        checker = false;
        break;
      } else {
        printf("Invalid input, quitting\n");
        checker = false;
        break;
      }

    } else if (option == 4) {
      printf("\"Bye Bye SearchNSort!\"\n");
      checker = false;
      break;
    } else
      printf("Enter a valid input!\n");
  }

  return 0;
}

int linearSearch(int v[], int e, int l) {
  for (int i = 0; i < l; i++)
    if (v[i] == e)
      return i;
  return -1;
}

void generate_arr(int *v, int length) {
  for (int i = 0; i < length; i++) {
    printf("Enter a number: ");
    scanf("%d", v + i);
  }

  for (int i = length; i < MAXVAL; i++)
    *(v + i) = INT_MIN;
}

int binarySearch(int v[], int e, int l) {
  int low, high, mid;

  low = 0;
  high = l - 1;
  mid = (low + high) / 2;
  while (low <= high && e != v[mid]) {
    if (e < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
    mid = (low + high) / 2;
  }
  if (e == v[mid])
    return mid;
  else
    return -1;
}

void selectionSortDec(int a[], int length) {
  for (int i = 0; i < length; i++) {
    int index = find_max(a, i, length);
    int temp = a[i];
    a[i] = a[index];
    a[index] = temp;
  }
}

int find_max(int v[], int s, int end) {
  int val = INT_MIN;
  int ans = -1;
  for (int i = s; i < end; i++)
    if (v[i] > val) {
      val = v[i];
      ans = i;
    }
  return ans;
}
