package AY2023;

import java.util.function.Supplier;

class Logger {
  boolean debugEnabled = false;

  public boolean isDebugEnabled() {
    return debugEnabled;
  }

  public String debug(Supplier<String> func) {
    return func.get();
  }
}

public class Q2D {
  public static String expensiveOperation() {
    return "Hello";
  }

  public static void main(String[] args) {
    Logger logger = new Logger();
    if (logger.isDebugEnabled()) {
      logger.debug(() -> "Look at this" + expensiveOperation());
    }
  }
}
