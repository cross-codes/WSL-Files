/* Codeforces solution file
Question: 1986/C*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
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

  void reverse(char[] arr, int idxStart, int idxEnd) {
    for (; idxStart < idxEnd; idxStart++, idxEnd--) {
      char temp = arr[idxStart];
      arr[idxStart] = arr[idxEnd];
      arr[idxEnd] = temp;
    }
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int n = readInt(), m = readInt();
      int[] indices = new int[m];
      String s = readString();

      for (int idx = 0; idx < m; idx++) indices[idx] = readInt();
      Arrays.sort(indices);

      char[] c = readString().toCharArray();
      Arrays.sort(c);
      reverse(c, 0, m - 1);

      char[] sChars = s.toCharArray();

      int upperLimit = 0;
      int cLower = 0;
      for (int idx = 0; idx < upperLimit; idx++) {
        int val = indices[idx];
        int currRedux = 0;
        while ((idx < upperLimit) && (indices[idx] == val)) {
          if (idx + 1 < upperLimit && indices[idx] == val) {
            sChars[indices[idx]] = c[m - 1 - upperLimit];
            idx++;
            currRedux++;
            System.err.println("hi");
          } else break;
        }
        sChars[indices[idx]] = c[cLower];
        cLower++;
        upperLimit += currRedux;
      }
      out.println(String.valueOf(sChars));
    }
  }
}
