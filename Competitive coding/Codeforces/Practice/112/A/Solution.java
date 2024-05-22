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
    char[] arr1 = readString().toLowerCase().toCharArray();
    char[] arr2 = readString().toLowerCase().toCharArray();
    int ans = 0;
    if (arr1[0] < arr2[0]) ans = -1;
    else if (arr1[0] > arr2[0]) ans = 1;
    else {
      for (int i = 1; i < arr1.length; i++) {
        if (arr1[i] < arr2[i]) {
          ans = -1;
          break;
        } else if (arr1[i] > arr2[i]) {
          ans = 1;
          break;
        }
      }
    }
    out.println(ans);
  }
}
