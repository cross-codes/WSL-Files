/* Codeforces solution file
Question: 1950/C*/
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
      System.err.println("Time = " + (t2 - t1) + " ms");
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
      String time = readString();
      String[] parts = time.split(":");
      int hours = Integer.valueOf(parts[0]), min = Integer.valueOf(parts[1]);
      boolean day;
      if (hours >= 12) {
        day = false;
        if (hours > 12) {
          hours = hours - 12;
        }
      } else {
        day = true;
        if (hours == 0) hours = 12;
      }
      String strH = String.valueOf(hours);
      if (strH.length() != 2) strH = "0" + strH;
      String minH = String.valueOf(min);
      if (minH.length() != 2) minH = "0" + minH;
      out.print(strH + ":" + minH);
      if (day) out.println(" AM");
      else out.println(" PM");
    }
  }
}
