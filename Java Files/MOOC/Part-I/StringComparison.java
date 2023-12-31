import java.util.Scanner;

public class StringComparison {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Input two strings");
    String first = scanner.nextLine();
    String second = scanner.nextLine();

    if (first.equals(second)) {
      System.out.println("The strings were the same!");
    } else {
      System.out.println("The strings were different!");
    }

    if (first.equals("two strings")) {
      System.out.println("Clever!");
    }

    if (second.equals("two strings")) {
      System.out.println("Sneaky");
    }
    scanner.close();
  }
}
