#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define MAXVAL 100

int vowels[5] = {'a', 'e', 'i', 'o', 'u'};
char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n',
                       'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

void count(char *str, int *vowelcount, int *consonantcount);

int main() {
  char string[MAXVAL];
  printf("Enter the sentence: ");
  scanf("%[^\n]%*c", string);
  int vowelcount = 0, consonantcount = 0;
  count(string, &vowelcount, &consonantcount);

  printf("The number of vowels and consonants are %d and %d respectively\n",
         vowelcount, consonantcount);
  return 0;
}

void count(char *str, int *vowelcount, int *consonantcount) {
  for (int i = 0; str[i] != '\0'; i++)
    for (int j = 0; j < 5; j++)
      if (tolower(str[i]) == vowels[j]) {
        *vowelcount += 1;
        break;
      }
  for (int i = 0; str[i] != '\0'; i++)
    for (int j = 0; j < 21; j++)
      if (tolower(str[i]) == consonants[j]) {
        *consonantcount += 1;
        break;
      }
}
