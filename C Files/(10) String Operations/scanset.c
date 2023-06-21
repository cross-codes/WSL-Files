#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int main() {
  char text[30];
  char sentence[100];
  printf("Enter a string: ");
  scanf("%[a-z]s", text); // Only accept input that satisfies being in a-z
  printf("The string is: %s\n", text);
  printf("Enter a sentence: ");
  scanf(" %[^\n]s", sentence); // Terminate only on newline
  printf("The entered sentence is: %s\n", sentence);
  return 0;
}
