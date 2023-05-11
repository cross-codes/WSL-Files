#include <stdio.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  printf("The address of 1 in arr is: %p\n", arr);

  char amessage[] = "This is a string";
  char *pmessage = "This is an array";
  printf("The address of T in pmessage is: %p\n", pmessage);
  printf("IDK what this is: %p\n", amessage);

  printf("This is the value of pmessage: %s\n", pmessage);

  return 0;
}
