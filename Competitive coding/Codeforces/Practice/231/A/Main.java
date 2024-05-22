import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    InputStreamReader in = new InputStreamReader(System.in);
    BufferedReader bf = new BufferedReader(in);
    int input = Integer.parseInt(bf.readLine().trim());
    int numAns = 0;
    while (input-- > 0) {
      String stream = bf.readLine().trim();
      String[] nums = stream.split(" ", -1);
      int count = 0;
      for (int i = 0; i < 3; i++) {
        if (Integer.parseInt(nums[i]) == 1) count++;
        if (count >= 2) {
          numAns++;
          break;
        }
      }
    }
    System.out.println(numAns);
  }
}
