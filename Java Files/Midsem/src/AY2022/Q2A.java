package AY2022;

import java.util.HashMap;

public class Q2A {
  public void run() {
    HashMap<Integer, Integer> cache = new HashMap<>();
    cache.put(1, 0);
    for (int i = 1; i <= 100; i++) {
      int nSteps = countSteps(i, cache);
      System.out.println("Hailstone(" + i + ") requires " + nSteps + " steps");
    }
  }

  private int countSteps(int n, HashMap<Integer, Integer> cache) {
    int nSteps = 0, nOrg = n;
    while (true) {
      if (cache.containsKey(n)) {
        nSteps += cache.get(n);
        cache.put(nOrg, nSteps);
        break;
      }
      if (n % 2 == 0) n /= 2;
      else n = 3 * n + 1;
      nSteps++;
    }
    return nSteps;
  }

  public static void main(String[] args) {
    new Q2A().run();
  }
}
