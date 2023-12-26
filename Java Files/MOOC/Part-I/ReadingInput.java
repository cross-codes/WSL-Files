import java.util.Scanner;

public class ReadingInput {
  public static void main(String[] args) {
    // Initiate a new resource "scanner"
    Scanner scanner = new Scanner(System.in);

    System.out.println("Write a message: ");

    // Assign a string message the contents of the input
    String message = scanner.nextLine();

    System.out.println(message + " welcome!");

    // Close the resource to prevent resource leaks
    scanner.close();
  }
}
