package AY2011;

import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.IntStream;

public class KeyFinder {
  public static final int MAX_THREADS = 4;
  private static AtomicInteger keyIndex = new AtomicInteger(-1);

  private KeyFinder() {
  }

  private static void linearSearchRange(int key, int[] array, int start, int end) {
    for (int idx = start; idx < end; idx++) {
      if (keyIndex.get() != -1)
        return;

      if (array[idx] == key) {
        keyIndex.compareAndSet(-1, idx);
        return;
      }
    }
  }

  public static void parallelSearch(int key, int[] array) {
    int n = array.length;

    Thread[] threads = IntStream.range(0, MAX_THREADS).mapToObj(i -> {
      Thread t = new Thread(() -> linearSearchRange(key, array, i, i + n / MAX_THREADS));
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

    if (keyIndex.get() != -1)
      System.out.println("Found key at: " + keyIndex);
    else
      System.out.println("Key not found");
  }
}
