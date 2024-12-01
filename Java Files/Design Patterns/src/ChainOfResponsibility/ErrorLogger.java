package ChainOfResponsibility;

public class ErrorLogger implements AbstractLogger {
  private AbstractLogger nextLogger;

  @Override
  public void logMessage(String message, int level) {
    if (level == 3) {
      System.out.println("ERROR: " + message);
    } else if (nextLogger != null) {
      nextLogger.logMessage(message, level);
    }
  }

  @Override
  public void setNextLogger(AbstractLogger logger) {
    this.nextLogger = logger;
  }
}
