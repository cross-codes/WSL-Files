package AY2022;

import java.util.HashMap;
import java.util.Map;

public class Q2B {
  public static String mostFrequentKmer(int k, String seq) {
    HashMap<String, Integer> freqs = new HashMap<>();
    int l = 0, r = k - 1, n = seq.length();
    while (r < n) {
      String subseq = seq.substring(l, r + 1);
      freqs.put(subseq, freqs.getOrDefault(subseq, 0) + 1);
      l++;
      r++;
    }
    int maxVal = Integer.MIN_VALUE;
    String res = "";
    for (Map.Entry<String, Integer> entry : freqs.entrySet()) {
      String key = entry.getKey();
      int value = entry.getValue();
      if (value > maxVal) {
        maxVal = value;
        res = key;
      }
    }
    return res;
  }

  public static void main(String[] args) {
    String s = "KRBOORBOKRB";
    System.out.println(mostFrequentKmer(3, s));
  }
}
