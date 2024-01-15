import java.util.Scanner;

public class Login {
  public static void main(String[] args) {
    String username1 = "alex";
    String username2 = "emma";
    String pwd1 = "sunshine";
    String pwd2 = "haskell";

    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter username: ");
    String username = scanner.nextLine();
    System.out.print("Enter password: ");
    String pwd = scanner.nextLine();

    if (username.equals(username1)) {
      if (pwd.equals(pwd1)) {
        System.out.println("You have succesfully logged in");
        scanner.close();
        return;
      }
    } else if (username.equals(username2)) {
      if (pwd.equals(pwd2)) {
        System.out.println("You have succesfully logged in");
        scanner.close();
        return;
      }
    }
    System.out.println("Incorrect username or password");
    scanner.close();
  }
}
