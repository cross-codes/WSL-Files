package AY2011;

import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;

public class ParallelSearchAndCount {
  public final int[] base;

  public ParallelSearchAndCount(int[] array) {
    this.base = array;
  }

  public void searchKey(int key) {
    KeyFinder.parallelSearch(key, this.base);
  }

  public ConcurrentHashMap<Integer, Integer> countFrequencyOfElements() {
    return FrequencyCounter.updateFrequency(this.base);
  }

  public static void main(String[] args) {
    Random random = new Random();
    int[] array = new int[10000000];
    for (int i = 0; i < array.length; i++) 
      array[i] = random.nextInt(100);

    ParallelSearchAndCount psc = new ParallelSearchAndCount(array);
    psc.searchKey(6);
    System.out.println(psc.countFrequencyOfElements());
  }
}
