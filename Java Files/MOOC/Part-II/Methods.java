import java.util.Scanner;

public class Methods {
  // The main is a method called by the OS via the runtime
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter the number of times to greet: ");
    int count = scanner.nextInt();
    for (int i = 0; i < count; i++) greet();
    greetRepeated(count);
    methodThatReturnsFloatingPointNumber();
    scanner.close();
  }

  public static void greet() {
    System.out.println("Greetings from the method world!");
  }

  public static void greetRepeated(int count) {
    for (int i = 0; i < count; i++) System.out.println("Greetings from the method world!");
  }

  public static double methodThatReturnsFloatingPointNumber() {
    return 2.0;
  }
}
