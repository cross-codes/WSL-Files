public class SumOfArray {
  public static void main(String[] args) {
    int[] numbers = {5, 1, 3, 4, 2};
    sumOfNumbersInArray(numbers);
  }

  public static void sumOfNumbersInArray(int[] nums) {
    int sum = 0;
    for (int idx = 0; idx < nums.length; idx++) {
      sum += nums[idx];
    }
    System.out.println(sum);
  }
}
