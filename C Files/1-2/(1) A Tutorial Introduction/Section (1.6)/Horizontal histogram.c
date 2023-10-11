#include <stdio.h>
/* Exercise (1.13) - My attempt */
#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 12

int main() {
  int c, i, lenw, state, j;
  int word_lengths[MAX_WORD_LENGTH];

  lenw = 0;
  state = OUT;

  for (i = 0; i < MAX_WORD_LENGTH; ++i)
    word_lengths[i] = 0;

  while ((c = getchar()) != EOF) {
    if (state == IN)
      lenw++;
    if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
      state = OUT;
      ++word_lengths[lenw - 1];
      lenw = 0;
    } else if (state == OUT) {
      state = IN;
    }
  }

  printf("\nLengths \n");

  for (i = 1; i < MAX_WORD_LENGTH; ++i) {
    printf("%5d :", i);
    for (j = 0; j < word_lengths[i]; ++j)
      printf("=");
    printf("\n");
  }
}
