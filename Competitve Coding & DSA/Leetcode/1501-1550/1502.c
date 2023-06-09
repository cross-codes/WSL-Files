void sw(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void quicksort(int v[], register int left, register int right) {
  int i, last;

  if (left >= right)
    return;
  sw(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (v[i] < v[left])
      sw(v, ++last, i);
  sw(v, left, last);
  quicksort(v, left, last - 1);
  quicksort(v, last + 1, right);
}

bool canMakeArithmeticProgression(int *v, int n) {

  quicksort(v, 0, n - 1);

  bool AP = false;
  int diff_for = v[1] - v[0];

  if (n == 2)
    return true;

  for (int k = 1; k < n - 1; k++) {
    int diff = v[k + 1] - v[k];
    if (diff != diff_for) {
      AP = false;
      break;
    } else {
      AP = true;
    }
  }

  return AP;
}
