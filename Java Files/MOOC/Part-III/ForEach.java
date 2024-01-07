import java.util.ArrayList;
import java.util.Scanner;

public class ForEach {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    ArrayList<Integer> numbers = new ArrayList<>();
    while (true) {
      int num = Integer.parseInt(scanner.nextLine());
      if (num == -1) {
        break;
      }
      numbers.add(num);
    }
    int sum = 0;
    for (Integer number : numbers) {
      sum += number;
    }
    System.out.println("Sum: " + sum);
    scanner.close();
  }
}
