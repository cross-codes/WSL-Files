package lab10;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ComputeFactorials {
  static long computeFactorial(int n) {
    if (n == 1)
      return n;
    return computeFactorial(n - 1) * n;
  }

  public static void main(String[] args) throws Throwable {
    ExecutorService executorService = Executors.newWorkStealingPool();
    Callable<Long> _5 = () -> {
      return computeFactorial(5);
    };

    Callable<Long> _7 = () -> {
      return computeFactorial(7);
    };
    Callable<Long> _10 = () -> {
      return computeFactorial(10);
    };

    Future<Long> res1 = executorService.submit(_5);
    Future<Long> res2 = executorService.submit(_7);
    Future<Long> res3 = executorService.submit(_10);

    System.out.println("Result 3: " + res3.get());
    System.out.println("Result 2: " + res2.get());
    System.out.println("Result 1: " + res1.get());

    executorService.shutdown();
  }
}
