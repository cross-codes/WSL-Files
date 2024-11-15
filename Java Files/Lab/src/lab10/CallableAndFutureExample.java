package lab10;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class CallableAndFutureExample {
  public static void main(String[] args) {
    ExecutorService executorService = Executors.newFixedThreadPool(3);
    Callable<Integer> task1 = () -> {
      System.out.println("Task 1 is being executex by " + Thread.currentThread().getName());
      Thread.sleep(1000);
      return 5 * 5;
    };

    Callable<Integer> task2 = () -> {
      System.out.println("Task 2 is being executed by " + Thread.currentThread().getName());
      Thread.sleep(2000);
      return 10 * 10;
    };

    try {
      Future<Integer> future1 = executorService.submit(task1);
      Future<Integer> future2 = executorService.submit(task2);
      System.out.println("Tasks are being computed...");
      Integer result1 = future1.get();
      Integer result2 = future2.get();
      System.out.println("Result of task 1: " + result1);
      System.out.println("Result of task 2: " + result2);
    } catch (Exception ex) {
      ex.printStackTrace();
    } finally {
      executorService.shutdown();
    }
  }
}
