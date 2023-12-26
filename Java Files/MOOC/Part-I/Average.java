import java.util.Scanner;

public class Average {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Give the first number:");
    String num1 = scanner.nextLine();

    System.out.println("Give the second number");
    String num2 = scanner.nextLine();
    double avg = (Double.parseDouble(num1) + Double.parseDouble(num2)) / 2;
    System.out.println("The average is " + avg);
    scanner.close();
  }
}
