#include <string.h>
int finalValueAfterOperations(char **operations, int operationsSize) {
  int ans = 0;
  char *increment = "++X";
  char *increment2 = "X++";
  char *decrement = "--X";
  char *decrement2 = "X--";

  for (int i = 0; i < operationsSize; i++) {
    if ((strcmp(increment, operations[i]) == 0) ||
        (strcmp(increment2, operations[i]) == 0))
      ans++;
    else if ((strcmp(decrement, operations[i]) == 0) ||
             (strcmp(decrement2, operations[i]) == 0))
      ans--;
  }

  return ans;
}
