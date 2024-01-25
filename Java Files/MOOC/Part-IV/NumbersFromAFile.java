import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;

public class NumbersFromAFile {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("File? ");
    String fileName = scanner.nextLine();
    System.out.print("Lower bound? ");
    int lowerBound = Integer.valueOf(scanner.nextLine());
    System.out.print("Upper bound? ");
    int upperBound = Integer.valueOf(scanner.nextLine());
    ArrayList<Integer> numbers = new ArrayList<>();
    try (Scanner fileReader = new Scanner(Paths.get(fileName))) {
      while (fileReader.hasNextLine()) {
        String line = fileReader.nextLine();
        if (line.isEmpty()) {
          continue;
        }
        int number = Integer.valueOf(line);
        if (number >= lowerBound && number <= upperBound) {
          numbers.add(number);
        }
      }
    } catch (Exception e) {
      System.out.println("Error: " + e.getMessage());
    }
    scanner.close();
    System.out.println("Numbers: " + numbers.size());
  }
}
