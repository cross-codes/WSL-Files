import java.util.Scanner;

public class Variables {
  public static void main(String[] args) {
    String text = "contains text";
    int integer = 123;
    double floatingPoint = 3.14159;
    boolean trueOrFalse = true;

    System.out.println("Text variable: " + text);
    System.out.println("Integer variable: " + integer);
    System.out.println("Floating-point variable: " + floatingPoint);
    System.out.println("Boolean: " + trueOrFalse);

    integer = 246;

    System.out.println("Updated integer: " + integer);

    // Default takes in string
    Scanner scanner = new Scanner(System.in);
    System.out.println("Write a value ");
    // <type>.valueOf(string) -> type casting
    int value = Integer.valueOf(scanner.nextLine());
    System.out.println("You wrote: " + value);

    // NOTE: Truthy values of a string are only case variations of the word "true"
    System.out.println("Write a string: ");
    boolean res = Boolean.valueOf(scanner.nextLine());
    System.out.println("That string was: " + res);

    scanner.close();
  }
}
