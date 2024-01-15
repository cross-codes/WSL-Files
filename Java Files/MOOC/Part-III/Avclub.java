import java.util.Scanner;

public class Avclub {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (true) {
      String text = scanner.nextLine();
      if (text.equals("")) {
        break;
      }
      String[] pieces = text.split(" ");
      for (int idx = 0; idx < pieces.length; idx++) {
        if ((pieces[idx]).contains("av")) {
          System.out.println(pieces[idx]);
        }
      }
    }
    scanner.close();
  }
}
