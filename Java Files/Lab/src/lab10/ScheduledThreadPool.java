package lab10;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;

public class ScheduledThreadPool {
  public static void main(String[] args) {
    ScheduledExecutorService executor = Executors.newScheduledThreadPool(1);
    Runnable printMessage = () -> System.out.println("Hello world!");
    ScheduledFuture<?> printer = executor.scheduleAtFixedRate(printMessage, 0, 2, TimeUnit.SECONDS);

    executor.schedule(() -> {
      printer.cancel(false);
      executor.shutdown();
    }, 10, TimeUnit.SECONDS);
  }
}
