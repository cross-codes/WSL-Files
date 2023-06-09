#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool charactercount(char *password) {
  if (strlen(password) >= 8)
    return true;
  return false;
}

bool uppercase(char *password) {
  for (int i = 0; i < strlen(password); i++)
    if (isupper(password[i]))
      return true;

  return false;
}

bool lowercase(char *password) {
  for (int i = 0; i < strlen(password); i++)
    if (islower(password[i]))
      return true;

  return false;
}

bool digit(char *password) {
  for (int i = 0; i < strlen(password); i++)
    if (isdigit(password[i]))
      return true;

  return false;
}

bool specialchars(char *password) {

  for (int i = 0; i < strlen(password); i++)
    if (ispunct(password[i]))
      return true;

  return false;
}

bool consecutives(char *password) {
  for (int i = 0; i < strlen(password) - 1; i++)
    if (password[i] == password[i + 1])
      return false;

  return true;
}

bool strongPasswordCheckerII(char *password) {
  return consecutives(password) && charactercount(password) &&
         uppercase(password) && lowercase(password) && digit(password) &&
         specialchars(password);
}
