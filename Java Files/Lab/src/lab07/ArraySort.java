package lab07;

import java.util.Arrays;

@FunctionalInterface
interface Comparator {
  public int compare(int a, int b);
}

public class ArraySort {
  public static void main(String[] args) {
    int[] array = { 4, 1, 2, 5 };
    Comparator comp = (a, b) -> Integer.compare(a, b);
    ArraySort.sort(array, comp);
    System.out.println(Arrays.toString(array));
  }

  public static void sort(int[] arr, Comparator comp) {
    int n = arr.length;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n - 1; j++) {
        if (comp.compare(arr[j], arr[j + 1]) > 0) {
          int temp = arr[j + 1];
          arr[j + 1] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
}
