/* Codeforces solution file
Question: 1980/A*/
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

  void shellsort(char v[], int n) {
    int gap = -1, i = -1, j = -1;
    char temp;

    for (gap = n / 2; gap > 0; gap /= 2)
      for (i = gap; i < n; i++)
        for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
          temp = v[j];
          v[j] = v[j + gap];
          v[j + gap] = temp;
        }
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int n = readInt(), m = readInt();
      char[] str = readString().toCharArray();
      int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
      for (int idx = 0; idx < n; idx++) {
        if (str[idx] == 'A') a++;
        else if (str[idx] == 'B') b++;
        else if (str[idx] == 'C') c++;
        else if (str[idx] == 'D') d++;
        else if (str[idx] == 'E') e++;
        else if (str[idx] == 'F') f++;
        else g++;
      }
      int ans = 0;
      if (a < m) ans = ans + m - a;
      if (b < m) ans = ans + m - b;
      if (c < m) ans = ans + m - c;
      if (d < m) ans = ans + m - d;
      if (e < m) ans = ans + m - e;
      if (f < m) ans = ans + m - f;
      if (g < m) ans = ans + m - g;
      out.println(ans);
    }
  }
}
