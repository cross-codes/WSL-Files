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
    int t = readInt();
    while (t-- > 0) {
      int n = readInt(), x = readInt();
      int oddCount = 0;
      for (int i = 0; i < n; i++) {
        if ((readInt() & 1) != 0) oddCount++;
      }
      int evenCount = n - oddCount;
      // Need at least one odd number
      if (oddCount-- >= 1) {
        // Remaining space: x - 1
        // Fill up completely with even numbers
        if (x - 1 - evenCount == 0) out.println("Yes");
        else {
          int maxOddPairs = oddCount / 2;
          if ((x - 1) % 2 == 0) {
            // Can fill up completely with odd pairs
            // Are the odd pairs sufficient
            if (maxOddPairs >= (x - 1) / 2) {
              out.println("Yes");
            } else if (x - 1 - 2 * maxOddPairs <= evenCount) out.println("Yes");
            else out.println("No");
          } else {
            // Use one even number, and perform the same operations above on the reduced space
            if (evenCount < 1) {
              out.println("No");
            } else {
              evenCount--;
              x--;
              if (maxOddPairs >= (x - 1) / 2) {
                out.println("Yes");
              } else if (x - 1 - 2 * maxOddPairs <= evenCount) out.println("Yes");
              else out.println("No");
            }
          }
        }
      } else {
        out.println("No");
      }
    }
  }
}
