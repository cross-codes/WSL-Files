import java.util.ArrayList;
import java.util.Scanner;

public class OnlyNumbers {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<>();
    while (true) {
      int temp = Integer.parseInt(scanner.nextLine());
      if (temp == -1) {
        break;
      }
      list.add(temp);
    }

    System.out.print("From where? ");
    int start = Integer.parseInt(scanner.nextLine());
    System.out.print("To where? ");
    int end = Integer.parseInt(scanner.nextLine());

    for (int i = start; i <= end; i++) {
      System.out.println(list.get(i));
    }
    scanner.close();
  }
}
