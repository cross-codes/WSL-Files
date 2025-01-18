class Main {
  public int maximumSubarraySum(int[] array) {
    int currentSum = 0;
    int bestSum = -1;

    for (int i = 0; i < array.length; i++) {
      int number = array[i];
      currentSum = Math.max(currentSum + number, number);
      bestSum = Math.max(currentSum, bestSum);
    }

    return bestSum;
  }
}
