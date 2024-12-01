package State;

public class OrderedState implements AbstractPackageState {
  @Override
  public void next(Package pkg) {
    pkg.setState(new DeliveredState());
  }

  @Override
  public void prev(Package pkg) {
    System.out.println("No valid previous states");
  }

  @Override
  public void printStatus() {
    System.out.println("Ordered state");
  }
}
