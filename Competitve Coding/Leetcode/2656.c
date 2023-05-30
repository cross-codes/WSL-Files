int maximizeSum(int *nums, int numsSize, int k) {
  register int ans = 0;
  register int gap, i, j, temp;

  for (gap = numsSize / 2; gap > 0; gap /= 2)
    for (i = gap; i < numsSize; i++)
      for (j = i - gap; j >= 0 && nums[j] > nums[j + gap]; j -= gap) {
        temp = nums[j];
        nums[j] = nums[j + gap];
        nums[j + gap] = temp;
      }
  ans += nums[numsSize - 1] * k + (k - 1) * k / 2;

  return ans;
}
