import java.util.Scanner;

public class SquareRootSum {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int num1 = scanner.nextInt();
    int num2 = scanner.nextInt();
    double sqaureRoot = Math.sqrt(num1 + num2);
    System.out.println(sqaureRoot);
    System.out.print("There is no line break added to the end of this line!");
    scanner.close();
  }
}
