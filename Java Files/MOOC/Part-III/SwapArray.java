import java.util.Scanner;

public class SwapArray {
  public static void main(String[] args) {
    int[] numbers = new int[5];
    for (int idx = 0; idx < 5; idx++) {
      numbers[idx] = 2 * idx + 1;
      System.out.println(numbers[idx]);
    }
    Scanner scanner = new Scanner(System.in);
    System.out.println("Give two indices to swap");
    int swp1 = scanner.nextInt();
    int swp2 = scanner.nextInt();

    int temp = numbers[swp1];
    numbers[swp1] = numbers[swp2];
    numbers[swp2] = temp;
    System.out.println();
    for (int idx = 0; idx < 5; idx++) {
      System.out.println(numbers[idx]);
    }
    scanner.close();
  }
}
