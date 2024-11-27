package AY2022;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.TreeMap;
import java.util.TreeSet;

public class OasisEventLeaderBoard {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);
    TreeMap<Integer, TreeSet<String>> scores = new TreeMap<>();

    int n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      String[] input = br.readLine().split(" ");
      int score = Integer.parseInt(input[1]);
      scores.computeIfAbsent(score, k -> new TreeSet<>()).add(input[0]);
    }

    if (scores.size() < 3) {
      out.println("NaN");
    } else {
      Iterator<Integer> it = scores.keySet().iterator();
      int cnt = 0;
      while (it.hasNext()) {
        if (cnt != 2) {
          cnt++;
          it.next();
        } else {
          TreeSet<String> teams = scores.get(it.next());
          for (String team : teams)
            out.println(team);
          break;
        }
      }
    }
    out.close();
  }
}
