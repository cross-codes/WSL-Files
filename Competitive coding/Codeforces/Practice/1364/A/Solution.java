import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {

  BufferedReader in;
  PrintWriter out;
  StringTokenizer tok = new StringTokenizer("");

  public static void main(String[] args) {
    new Thread(null, new Solution(), "", 256 * (1L << 20)).start();
  }

  public void run() {
    try {
      long t1 = 0;
      boolean isJudge = System.getProperty("ONLINE_JUDGE") != null;
      if (isJudge) {
        in = new BufferedReader(new InputStreamReader(System.in), 32768);
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out), 32768));
      } else {
        t1 = System.currentTimeMillis();
        in = new BufferedReader(new FileReader("input.txt"), 32768);
        out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt"), 32768));
      }
      Locale.setDefault(Locale.US);
      solve();
      in.close();
      out.close();
      if (!isJudge) {
        long t2 = System.currentTimeMillis();
        System.err.println("Time = " + (t2 - t1) + " ms");
      }
    } catch (Throwable t) {
      t.printStackTrace(System.err);
      System.exit(-1);
    }
  }

  String readString() throws IOException {
    while (!tok.hasMoreTokens()) {
      tok = new StringTokenizer(in.readLine());
    }
    return tok.nextToken();
  }

  int readInt() throws IOException {
    return Integer.parseInt(readString());
  }

  long readLong() throws IOException {
    return Long.parseLong(readString());
  }

  double readDouble() throws IOException {
    return Double.parseDouble(readString());
  }

  void solve() throws IOException {
    // Three cases arise:
    // Either all numbers are divisible by x -> output -1
    // Sum of all numbers are not divisible by x -> output n
    // Else, the sum is divisible by x, but all the numbers are not divisible by x
    // In this case, subtracting a multiple of x does no good, so find the earliest
    // non multiple of x from either end, and return the length of the rest
    int t = readInt();
    while (t-- > 0) {
      boolean cond1 = true;
      int n = readInt(), x = readInt();
      long sum = 0;
      int[] arr = new int[n];
      for (int i = 0; i < n; i++) {
        int num = readInt();
        if (cond1) {
          cond1 = (num % x == 0);
        }
        sum += num;
        arr[i] = num;
      }
      if (cond1) {
        out.println(-1);
      } else if (sum % x != 0) {
        out.println(n);
      } else {
        int startIdx = 0, endIdx = n - 1;
        while (arr[startIdx] % x == 0 && startIdx < n) {
          startIdx++;
        }
        while (arr[endIdx] % x == 0 && endIdx > -1) {
          endIdx--;
        }
        int minVal = Math.min(startIdx, n - 1 - endIdx);
        out.println(n - minVal - 1);
      }
    }
  }
}
