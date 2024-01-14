public class PrintNeatly {
  public static void main(String[] args) {
    int[] array = {5, 1, 3, 4, 2};
    printNeatly(array);
  }

  public static void printNeatly(int[] arr) {
    System.out.print(arr[0] + ",");
    for (int idx = 1; idx < arr.length - 1; idx++) {
      System.out.print(" " + arr[idx] + ",");
    }
    System.out.println(" " + arr[arr.length - 1]);
  }
}
