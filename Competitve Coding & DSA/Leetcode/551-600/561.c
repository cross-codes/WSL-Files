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

int arrayPairSum(int *nums, int numsSize) {
  quicksort(nums, 0, numsSize - 1);
  int ans = 0;
  for (int i = 0; i < numsSize; i += 2)
    ans += nums[i];

  return ans;
}
