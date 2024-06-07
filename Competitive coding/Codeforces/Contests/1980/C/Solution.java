/* Codeforces solution file
Question: 1980/C*/
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

  void shellsort(int v[], int n) {
    int gap = -1, i = -1, j = -1, temp = -1;

    for (gap = n / 2; gap > 0; gap /= 2)
      for (i = gap; i < n; i++)
        for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
          temp = v[j];
          v[j] = v[j + gap];
          v[j + gap] = temp;
        }
  }

  int bsearch(int v[], int n, int T) {
    int L = 0, R = n - 1, m = 0;
    while (L != R) {
      if ((L + R) % 2 != 0) m = (L + R) / 2 + 1;
      else m = (L + R) / 2;
      if (v[m] > T) R = m - 1;
      else L = m;
    }
    if (v[L] == T) return L;
    else return -1;
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int n = readInt();
      int[] original_arr = new int[n], new_arr = new int[n];
      for (int idx = 0; idx < n; idx++) original_arr[idx] = readInt();
      for (int idx = 0; idx < n; idx++) new_arr[idx] = readInt();
      int d = readInt();
      int d_arr[] = new int[d];
      for (int idx = 0; idx < d; idx++) d_arr[idx] = readInt();
      boolean no_repl = true;
      for (int elem : d_arr) {
        boolean end = true;
        for (int idx = 0; idx < n; idx++) {
          if (new_arr[idx] == elem) {
            if (original_arr[idx] != elem) {
              end = false;
              original_arr[idx] = elem;
              break;
            }
          }
        }
        if (end) {
          no_repl = true;
          for (int idx = 0; idx < n; idx++) {
            if (new_arr[idx] != original_arr[idx]) {
              original_arr[idx] = elem;
              no_repl = false;
              break;
            }
          }
        }
        if (no_repl) {
          out.println("NO");
          break;
        }
      }
      boolean caught = false;
      if (!no_repl) {
        for (int idx = 0; idx < n; idx++) {
          if (new_arr[idx] != original_arr[idx]) {
            out.println("NO");
            caught = true;
            break;
          }
        }
        if (!caught) out.println("YES");
      }
    }
  }
}
