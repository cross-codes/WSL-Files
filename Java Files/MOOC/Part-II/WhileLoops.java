import java.util.Scanner;

public class WhileLoops {
  public static void main(String[] args) {
    int number = 1;

    while (true) {
      System.out.println(number);
      if (number >= 5) {
        break;
      }
      number += 1;
    }
    Scanner scanner = new Scanner(System.in);
    while (true) {
      System.out.println("Exit? (y exits)");
      String input = scanner.nextLine();
      if (input.equals("y")) {
        break;
      }
      System.out.println("Ok! Let's carry on");
    }
    System.out.println("Ready!");

    while (true) {
      System.out.println("Insert positive integers");
      int integer = Integer.valueOf(scanner.nextLine());

      if (integer <= 0) {
        System.out.println("Unfit number! Try again");
        continue;
      }
      System.out.println("Your input was " + integer);
      break;
    }
    scanner.close();
  }
}
