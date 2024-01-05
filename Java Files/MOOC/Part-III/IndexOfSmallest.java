import java.util.ArrayList;
import java.util.Scanner;

public class IndexOfSmallest {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<>();
    while (true) {
      int temp = Integer.parseInt(scanner.nextLine());
      if (temp == 9999) {
        break;
      }
      list.add(temp);
    }

    int min = Integer.MAX_VALUE;
    for (int i = 0; i < list.size(); i++) {
      if (list.get(i) < min) {
        min = list.get(i);
      }
    }
    System.out.println("Smallest number: " + min);

    for (int j = 0; j < list.size(); j++) {
      if (min == list.get(j)) {
        System.out.println("Found at index: " + j);
      }
    }

    scanner.close();
  }
}
