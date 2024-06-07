/* Codeforces solution file
Question: 1945/C*/
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

  int numberOfZeroes(char[] arr, int idxStart, int idxEnd) {
    int ans = 0;
    for (int idx = idxStart; idx <= idxEnd; idx++) {
      if (arr[idx] == '0') ans++;
    }
    return ans;
  }

  int numberOfOnes(char[] arr, int idxStart, int idxEnd) {
    int ans = 0;
    for (int idx = idxStart; idx <= idxEnd; idx++) {
      if (arr[idx] == '1') ans++;
    }
    return ans;
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int n = readInt();
      char[] arr = readString().toCharArray();
      int posgolow = n / 2, posgohigh = n / 2;
      while (posgohigh < n || posgolow > 0) {
        // posgolow
        if (posgolow > 0
            && numberOfZeroes(arr, 0, posgolow) >= Math.ceil(posgolow / 2)
            && numberOfOnes(arr, posgolow + 1, n - 1) >= Math.ceil((n - posgolow) / 2)) {
          out.println(posgolow + 1);
          break;
        }

        if (posgohigh < n
            && numberOfZeroes(arr, 0, posgohigh) >= Math.ceil(posgohigh / 2)
            && numberOfOnes(arr, posgohigh + 1, n - 1) >= Math.ceil((n - posgohigh) / 2)) {
          out.println(posgohigh - 1);
          break;
        }
        posgolow--;
        posgohigh++;
      }
    }
  }
}
