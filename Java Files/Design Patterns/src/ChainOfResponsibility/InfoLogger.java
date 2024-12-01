package ChainOfResponsibility;

public class InfoLogger implements AbstractLogger {
  private AbstractLogger nextLogger;

  @Override
  public void logMessage(String message, int level) {
    if (level == 1) {
      System.out.println("INFO: " + message);
    } else if (nextLogger != null) {
      nextLogger.logMessage(message, level);
    }
  }

  @Override
  public void setNextLogger(AbstractLogger logger) {
    this.nextLogger = logger;
  }
}
