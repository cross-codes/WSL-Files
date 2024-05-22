/* Codeforces solution file
Question: 1933/E*/
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
      long t1 = System.currentTimeMillis();
      if (System.getProperty("ONLINE_JUDGE") != null) {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      } else {
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
      }
      Locale.setDefault(Locale.US);
      solve();
      in.close();
      out.close();
      long t2 = System.currentTimeMillis();
      System.err.println("Time = " + (t2 - t1));
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
      int n = readInt();
      int[] sections = new int[n]; // a1, a2, a3, a4 ...
      for (int i = 0; i < n; i++) sections[i] = readInt();
      int q = readInt();
      int[] possible = new int[n];
      int[] possiblePerformanceIncrease = new int[n];
      int idx = 0;
      while (q-- > 0) {
        idx = 0;
        // sum from l to r where l <= r <= n
        int l = readInt(), u = readInt(), r = l;
        int currSum = 0; // Sections
        // Summation from l to r
        for (; r < n; r++) {
          currSum = 0;
          for (int i = l; i < r; i++) currSum += sections[i - 1];
          possible[idx] = r;
          possiblePerformanceIncrease[idx] = currSum * u - (r * (r - 1)) / 2;
          idx++;
        }
        // Find the maximum performace increase
        int maxPerform = Integer.MIN_VALUE;
        for (int i = 0; i < idx; i++)
          if (possiblePerformanceIncrease[i] > maxPerform)
            maxPerform = possiblePerformanceIncrease[i];
        // Find the corresponding index
        for (int j = 0; j < idx; j++)
          if (possiblePerformanceIncrease[j] == maxPerform) {
            out.print(possible[j]);
            out.print("");
            break;
          }
      }
      out.println();
    }
  }
}
