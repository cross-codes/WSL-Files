package lab10;

import java.util.concurrent.CopyOnWriteArrayList;

public class CopyOnWriteArrayListExample {
  public static void main(String[] args) {
    CopyOnWriteArrayList<Integer> list = new CopyOnWriteArrayList<>();

    Runnable task = () -> {
      for (int i = 0; i < 5; i++) {
        list.add(i);
        System.out.println(Thread.currentThread().getName() + " added " + i + ": " + list);
      }

      try {
        Thread.sleep(100);
      } catch (Exception e) {
        e.printStackTrace();
      }
    };

    Thread t1 = new Thread(task, "Thread 1");
    Thread t2 = new Thread(task, "Thread 2");

    t1.start();
    t2.start();

    try {
      t1.join();
      t2.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("Final list: " + list);
  }
}
