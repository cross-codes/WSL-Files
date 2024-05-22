/* Codeforces solution file
Question: 1933/C*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
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
      // l = k a^x b^y
      int a = readInt(), b = readInt(), l = readInt();
      int xMax = 0, yMax = 0;
      while (true) {
        if ((int) (l / Math.pow(a, xMax)) <= 1) break;
        xMax++;
      }
      while (true) {
        if ((int) (l / Math.pow(b, yMax)) <= 1) break;
        yMax++;
      }
      ArrayList<Double> numPossible = new ArrayList<>();
      for (int j = 0; j <= xMax; j++) {
        for (int k = 0; k <= yMax; k++) {
          double result = l / (Math.pow(a, j) * Math.pow(b, k));
          if (result >= 1 && result % 1 == 0 && !numPossible.contains(result))
            numPossible.add(result);
        }
      }
      out.println(numPossible.size());
    }
  }
}
