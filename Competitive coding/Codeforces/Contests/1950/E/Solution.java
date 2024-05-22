/* Codeforces solution file
Question: 1950/E*/
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

  int isSubstringAnswer(String parent, String sub) {
    double repeats = (parent.length() / sub.length());
    if (repeats != (int) repeats) return -1;
    else {
      String newSub = "";
      for (int i = 0; i < (int) repeats; i++) newSub += sub;
      char[] subarr = newSub.toCharArray(), parr = parent.toCharArray();
      int diff = 0;
      for (int j = 0; j < parent.length(); j++) {
        if (diff > 1) return -1;
        else if (subarr[j] != parr[j]) diff++;
      }
      return (diff > 1) ? -1 : 1;
    }
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int len = readInt();
      boolean cond = false;
      String str = readString();
      char[] strarr = str.toCharArray();
      int sl = 1, slMax = len / 2;
      for (; sl <= slMax; sl++) {
        if ((len % sl) != 0) continue;
        for (int sidx = 0; sidx <= len - sl; sidx++) {
          String sub = "";
          for (int i = 0; i < sl; i++) sub += strarr[sidx + i];
          int ans = isSubstringAnswer(str, sub);
          if (ans == 1) {
            out.println(sl);
            cond = true;
            break;
          }
        }
        if (cond) break;
      }
      if (!cond) out.println(len);
    }
  }
}
