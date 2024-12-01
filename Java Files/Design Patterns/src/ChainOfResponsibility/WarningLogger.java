package ChainOfResponsibility;

public class WarningLogger implements AbstractLogger {
  private AbstractLogger nextLogger;

  @Override
  public void logMessage(String message, int level) {
    if (level == 2) {
      System.out.println("WARN: " + message);
    } else if (nextLogger != null) {
      nextLogger.logMessage(message, level);
    }
  }

  @Override
  public void setNextLogger(AbstractLogger logger) {
    this.nextLogger = logger;
  }
}
