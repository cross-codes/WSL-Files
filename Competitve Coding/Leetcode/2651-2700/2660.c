int isWinner(int *player1, int player1Size, int *player2, int player2Size) {
  register int p1 = 0;
  register int p2 = 0;
  int check = 0;

  for (int i = 0; i < player1Size; i++) {
    if (check != 0) {
      p1 += 2 * player1[i];
      if (player1[i] != 10)
        check--;
      else
        check = 2;
    } else {
      if (player1[i] == 10) {
        check = 2;
        p1 += player1[i];
      } else {
        p1 += player1[i];
      }
    }
  }

  check = 0;

  for (int i = 0; i < player2Size; i++) {
    if (check != 0) {
      p2 += 2 * player2[i];
      if (player2[i] != 10)
        check--;
      else
        check = 2;
    } else {
      if (player2[i] == 10) {
        check = 2;
        p2 += player2[i];
      } else {
        p2 += player2[i];
      }
    }
  }

  if (p1 > p2) {
    return 1;
  } else if (p1 < p2) {
    return 2;
  } else
    return 0;
}
