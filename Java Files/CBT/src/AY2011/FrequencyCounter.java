package AY2011;

import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.IntStream;

public class FrequencyCounter {
  public static final int MAX_THREADS = 4;
  private static final ConcurrentHashMap<Integer, Integer> freq = new ConcurrentHashMap<>();

  private FrequencyCounter() {
  }

  private static void linearUpdateFrequencyRange(int[] array, int start, int end) {
    for (int i = start; i < end; i++)
      freq.put(array[i], freq.getOrDefault(array[i], 0) + 1);
  }

  public static ConcurrentHashMap<Integer, Integer> updateFrequency(int[] array) {
    int n = array.length;

    Thread[] threads = IntStream.range(0, MAX_THREADS).mapToObj(i -> {
      Thread t = new Thread(() -> linearUpdateFrequencyRange(array, i, i + n / MAX_THREADS));
      t.start();
      return t;
    }).toArray(Thread[]::new);

    for (Thread t : threads) {
      try {
        t.join();
      } catch (InterruptedException ex) {
        ex.printStackTrace(System.err);
      }
    }

    return freq;
  }

}
