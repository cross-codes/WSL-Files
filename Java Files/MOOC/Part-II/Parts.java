import java.util.Scanner;

public class Parts {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int count = 0;
    int sum = 0;
    int evenNumbers = 0;
    System.out.println("Give numbers:");
    while (true) {
      int temp = Integer.parseInt(scanner.nextLine());
      if (temp != -1) {
        count++;
        sum += temp;
        if (temp % 2 == 0) {
          evenNumbers++;
        }
      } else {
        System.out.println("Thanks! Bye!");
        break;
      }
    }
    System.out.println("Sum: " + sum);
    System.out.println("Numbers: " + count);
    System.out.println("Average: " + (double) sum / count);
    System.out.println("Even: " + evenNumbers);
    System.out.println("Odd: " + (count - evenNumbers));
    scanner.close();
  }
}
