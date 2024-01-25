import java.util.ArrayList;
import java.util.Scanner;

public class NumberOfStrings {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<String> strings = new ArrayList<>();
    while (true) {
      String input = scanner.nextLine();
      if (input.equals("end")) {
        break;
      }
      strings.add(input);
    }
    System.out.println(strings.size());
    scanner.close();
  }
}
