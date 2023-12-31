import java.util.Scanner;

public class Conditionals {
  public static void main(String[] args) {
    System.out.println("Hello World");
    if (true) {
      System.out.println("This code is unavoidable");
    }
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter your speed:");
    int speed = scanner.nextInt();
    if (speed > 120) {
      System.out.println("Speeding ticket!");
    }
    System.out.println("Give a number:");
    int num = scanner.nextInt();
    if (num > 0) {
      System.out.println("The number is positive");
    } else {
      System.out.println("The number is not positive");
    }
    scanner.close();
  }
}
