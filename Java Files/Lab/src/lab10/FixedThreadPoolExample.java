package lab10;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class FixedThreadPoolExample {
  public static void main(String[] args) {
    ExecutorService executor = Executors.newFixedThreadPool(3);
    for (int i = 1; i <= 5; i++) {
      int taskNumber = i;
      executor.submit(() -> {
        System.out.println("Task " + taskNumber + " is being executed by " + Thread.currentThread().getName());
        try {
          Thread.sleep(2000);
        } catch (InterruptedException ex) {
          ex.printStackTrace();
        }
      });
    }
    executor.shutdown();
  }
}
