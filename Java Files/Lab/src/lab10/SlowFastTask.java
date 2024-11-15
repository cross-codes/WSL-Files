package lab10;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class SlowFastTask {
  public static void main(String[] args) throws ExecutionException, InterruptedException {
    ExecutorService executor = Executors.newFixedThreadPool(2);
    Callable<String> slow = () -> {
      Thread.sleep(1000);
      return "Slow thread done";
    };

    Callable<String> fast = () -> {
      return "Fast thread done";
    };

    Future<String> slowResult = executor.submit(slow);
    Future<String> fastResult = executor.submit(fast);

    try {
      String res = slowResult.get(900, TimeUnit.MILLISECONDS);
      System.out.println(res);
    } catch (TimeoutException ex) {
      System.out.println("Too slow");
    }

    String res = fastResult.get();
    System.out.println(res);

    executor.shutdown();
  }
}
