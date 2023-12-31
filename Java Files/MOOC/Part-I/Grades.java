import java.util.Scanner;

public class Grades {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter your points");
    int points = scanner.nextInt();
    if (points < 0) {
      System.out.println("Impossible!");
    } else if ((0 <= points) && (points <= 49)) {
      System.out.println("Failed");
    } else if ((50 <= points) && (points <= 59)) {
      System.out.println("1");
    } else if ((60 <= points) && (points <= 69)) {
      System.out.println("2");
    } else if ((70 <= points) && (points <= 79)) {
      System.out.println("3");
    } else if ((80 <= points) && (points <= 89)) {
      System.out.println("4");
    } else if ((90 <= points) && (points <= 100)) {
      System.out.println("5");
    } else {
      System.out.println("Incredible!");
    }
    scanner.close();
  }
}
