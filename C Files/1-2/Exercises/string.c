#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

int stringlength(char *str);
int stringcompare(char *str1, char *str2);

int main() {
  char *str1 = "akshaj";
  char *str2 = "akshaj";
  char *str3 = "akshays";

  printf("%d - str1\n", stringlength(str1));
  printf("%d - str2\n", stringlength(str2));
  printf("%d - str3\n", stringlength(str3));
  printf("%d - comp str1 and str2\n", stringcompare(str1, str2));
  printf("%d - comp str1 and str3\n", stringcompare(str1, str3));
  return 0;
}

int stringlength(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
    count++;

  return count;
}

int stringcompare(char *str1, char *str2) {
  int l1 = stringlength(str1), l2 = stringlength(str2);

  if (l1 != l2)
    return 0;

  for (int i = 0; i < l1; i++) {
    if (str1[i] != str2[i])
      return 0;
  }
  return 1;
}
