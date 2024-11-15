package lab06;

import java.util.stream.Stream;

public class RaggedArray {
  public static void main(String[] args) {
    int[][] rgArray = new int[4][];
    rgArray =
        Stream.of(new int[] {1, 2, 3, 4}, new int[] {5, 6, 7}, new int[] {8, 9}, new int[] {10})
            .toArray(int[][]::new);

    int sum = 0;
    for (int i = 0; i < rgArray.length; i++) {
      int[] subArray = rgArray[i];
      for (int j = 0; j < subArray.length; j++) sum += subArray[j];
    }

    System.out.println(sum);
  }
}
