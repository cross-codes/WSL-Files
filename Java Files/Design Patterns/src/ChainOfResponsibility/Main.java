package ChainOfResponsibility;

public class Main {
  public static void main(String... args) {
    AbstractLogger infoLogger = new InfoLogger();
    AbstractLogger warningLogger = new WarningLogger();
    AbstractLogger errorLogger = new ErrorLogger();

    infoLogger.setNextLogger(warningLogger);
    warningLogger.setNextLogger(errorLogger);

    infoLogger.logMessage("Info logger was responsible for this", 3);
  }
}
