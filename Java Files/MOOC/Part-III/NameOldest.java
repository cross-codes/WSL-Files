import java.util.Scanner;

public class NameOldest {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int max_age = Integer.MIN_VALUE;
    String oldest = "undef";
    while (true) {
      String text = scanner.nextLine();
      if (text.equals("")) {
        break;
      }
      String[] parts = text.split(",");
      if (Integer.valueOf(parts[1]) > max_age) {
        oldest = parts[0];
      }
    }
    System.out.println("Name of the oldest: " + oldest);
    scanner.close();
  }
}
