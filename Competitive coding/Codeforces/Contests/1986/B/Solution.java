/* Codeforces solution file
Question: 1986/B*/
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

  boolean isThisCellReal(int i, int j, int[][] arr, int rows, int columns) {
    if (i < 0) return false;
    if (j < 0) return false;
    if (i > rows - 1) return false;
    if (j > columns - 1) return false;
    return true;
  }

  void solve() throws IOException {
    int t = readInt();
    while (t-- > 0) {
      int rows = readInt(), columns = readInt();
      int[][] matrix = new int[rows][columns];

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          matrix[i][j] = readInt();
        }
      }

      while (true) {
        boolean operationPerformed = false;
        int currRow = 0, currColumn = 0;
        for (; currRow < rows; currRow++) {
          for (currColumn = 0; currColumn < columns; currColumn++) {
            int val = matrix[currRow][currColumn];
            int maxDiff = Integer.MAX_VALUE;
            boolean sub = false;
            if (isThisCellReal(currRow - 1, currColumn, matrix, rows, columns)) {
              if (val <= matrix[currRow - 1][currColumn]) continue;
              if (val - matrix[currRow - 1][currColumn] < maxDiff) {
                maxDiff = val - matrix[currRow - 1][currColumn];
                sub = true;
              }
            }
            if (isThisCellReal(currRow, currColumn - 1, matrix, rows, columns)) {
              if (val <= matrix[currRow][currColumn - 1]) continue;
              if (val - matrix[currRow][currColumn - 1] < maxDiff) {
                sub = true;
                maxDiff = val - matrix[currRow][currColumn - 1];
              }
            }
            if (isThisCellReal(currRow + 1, currColumn, matrix, rows, columns)) {
              if (val <= matrix[currRow + 1][currColumn]) continue;
              if (val - matrix[currRow + 1][currColumn] < maxDiff) {
                sub = true;
                maxDiff = val - matrix[currRow + 1][currColumn];
              }
            }
            if (isThisCellReal(currRow, currColumn + 1, matrix, rows, columns)) {
              if (val <= matrix[currRow][currColumn + 1]) continue;
              if (val - matrix[currRow][currColumn + 1] < maxDiff) {
                sub = true;
                maxDiff = val - matrix[currRow][currColumn + 1];
              }
            }
            if (sub) {
              matrix[currRow][currColumn] = val - maxDiff;
              operationPerformed = true;
              break;
            }
          }
          if (operationPerformed) break;
        }
        if (!operationPerformed) break;
      }

      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          out.print(matrix[i][j] + " ");
        }
        out.println();
      }
    }
  }
}
