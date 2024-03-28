import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
        out = new PrintWriter(System.out);
      } else {
        in = new BufferedReader(new FileReader("input.txt"));
        out = new PrintWriter("output.txt");
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
    String nstr = readString().trim();
    String kstr = readString().trim();
    int n = Integer.parseInt(nstr), k = Integer.parseInt(kstr), idx = -1;
    int[] nums = new int[n];
    while (++idx < n) {
      String mark = readString().trim();
      nums[idx] = Integer.parseInt(mark);
    }
    int minScore = (nums[k - 1] > 0) ? nums[k - 1] : 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] >= minScore) ans++;
    }
    out.println(ans);
  }
}
