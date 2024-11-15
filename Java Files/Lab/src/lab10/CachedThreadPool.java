package lab10;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class CachedThreadPool {
  public static void main(String[] args) throws InterruptedException, ExecutionException {
    ExecutorService executorService = Executors.newCachedThreadPool();
    Callable<Integer> task1 = () -> {
      Thread.sleep(100);
      return 5 * 5;
    };

    Callable<Integer> task2 = () -> {
      Thread.sleep(200);
      return 10 * 10;
    };

    Callable<Integer> task3 = () -> {
      Thread.sleep(300);
      return 7 * 7;
    };

    Callable<Integer> task4 = () -> {
      Thread.sleep(400);
      return 9 * 9;
    };

    Future<Integer> res1 = executorService.submit(task1);
    Future<Integer> res2 = executorService.submit(task2);
    Future<Integer> res3 = executorService.submit(task3);
    Future<Integer> res4 = executorService.submit(task4);

    System.out.println(res1.get() + res2.get() + res3.get() + res4.get());
    executorService.shutdown();
  }
}
