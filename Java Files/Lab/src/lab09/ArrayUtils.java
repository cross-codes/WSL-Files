package lab09;

import java.util.Arrays;

public class ArrayUtils {
  public static void sortArray(int[] array) {
    Arrays.sort(array);
    for (int i = 0; i < array.length - 1; i++) {
      assert array[i] <= array[i + 1] : "Array not sorted properly";
    }
  }

  public static void main(String[] args) {
    int[] sortedArray = { 1, 2, 3, 4, 5 };

    System.out.println("Testing with sorted array: " + Arrays.toString(sortedArray));
    ArrayUtils.sortArray(sortedArray);
    System.out.println("Test case 1 passed");

    int[] unsortedArray = { 5, 2, 4, 1, 3 };
    System.out.println("Testing with an unsorted array: " +
        Arrays.toString(unsortedArray));
    ArrayUtils.sortArray(unsortedArray);
    System.out.println("Test case 2 passed.");
    int[] invalidArray = { 5, 3, 4, 2, 1 };
    System.out.println("Testing with an invalid (unsorted) array: " +
        Arrays.toString(invalidArray));
    try {
      ArrayUtils.sortArray(invalidArray);
    } catch (AssertionError e) {
      System.out.println("AssertionError caught: " + e.getMessage());
    }
  }
}
