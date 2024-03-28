import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    InputStreamReader in = new InputStreamReader(System.in);
    BufferedReader bf = new BufferedReader(in);
    int input = Integer.parseInt(bf.readLine().trim());
    while (input-- > 0) {
      String test = bf.readLine().trim();
      if (test.length() > 10) {
        String firstChar = String.valueOf(test.charAt(0));
        String count = String.valueOf(test.length() - 2);
        String lastChar = String.valueOf(test.charAt(test.length() - 1));
        System.out.println(firstChar + count + lastChar);
      } else System.out.println(test);
    }
  }
}
