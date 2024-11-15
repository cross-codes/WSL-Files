package lab10;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SynchronizedListExample {
  public static void main(String[] args) {
    List<Integer> list = new ArrayList<>();
    List<Integer> synchronizedList = Collections.synchronizedList(list);

    Runnable task = () -> {
      for (int i = 0; i < 500; i++) {
        synchronizedList.add(i);
        System.out.println(Thread.currentThread().getName() + " added: " + i);
        try {
          Thread.sleep(100);
        } catch (InterruptedException ex) {
          ex.printStackTrace(System.err);
        }
      }
    };

    Thread thread1 = new Thread(task, "Thread 1");
    Thread thread2 = new Thread(task, "Thread 2");

    thread1.start();
    thread2.start();

    try {
      thread1.join();
      thread2.join();
    } catch (InterruptedException ex) {
      ex.printStackTrace(System.err);
    }

    System.out.println("Final list: " + synchronizedList);
  }
}
