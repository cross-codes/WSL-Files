import java.util.Scanner;

public class Calculator {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Give the first number: ");
    Double num1 = Double.parseDouble(scanner.nextLine());
    System.out.println("Give the second number: ");
    Double num2 = Double.parseDouble(scanner.nextLine());

    System.out.println(num1 + " + " + num2 + " = " + (num1 + num2));
    System.out.println(num1 + " - " + num2 + " = " + (num1 - num2));
    System.out.println(num1 + " * " + num2 + " = " + (num1 * num2));
    System.out.println(num1 + " / " + num2 + " = " + (num1 / num2));
    scanner.close();
  }
}
