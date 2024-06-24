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

  boolean isConsonant(char c) {
    return !(c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I' || c == 'a'
        || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i');
  }

  void solve() throws IOException {
    char[] input = readString().toCharArray();
    StringBuffer ans = new StringBuffer("");
    int n = input.length;
    for (int idx = 0; idx < n; idx++) {
      if (isConsonant(input[idx])) {
        ans.append(".");
        if (input[idx] <= 90) ans.append(Character.toLowerCase(input[idx]));
        else ans.append(input[idx]);
      }
    }
    out.println(ans);
  }
}
