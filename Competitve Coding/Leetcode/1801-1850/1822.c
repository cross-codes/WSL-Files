int arraySign(int *v, int n) {
  int exit = -1, neg_count = 0;

  for (int i = 0; i < n; i++) {
    (v[i] < 0) ? neg_count++ : ((v[i] == 0) ? (exit = 1) : 0);
    if (exit == 1)
      return 0;
  }

  return ((neg_count % 2 == 0) ? 1 : -1);
}
