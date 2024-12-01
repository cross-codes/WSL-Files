package State;

public class Main {
  public static void main(String... args) {
    Package pkg = new Package();
    pkg.nextState();
    pkg.nextState();
    pkg.previousState();
    pkg.printStatus();
  }
}
