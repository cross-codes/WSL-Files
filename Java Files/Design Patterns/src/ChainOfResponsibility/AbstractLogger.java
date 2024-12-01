package ChainOfResponsibility;

public interface AbstractLogger {
  void logMessage(String message, int level);

  void setNextLogger(AbstractLogger nextLogger);
}
