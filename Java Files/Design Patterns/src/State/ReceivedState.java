package State;

public class ReceivedState implements AbstractPackageState {
  @Override
  public void next(Package pkg) {
    System.out.println("No valid state to go to");
  }

  @Override
  public void prev(Package pkg) {
    pkg.setState(new DeliveredState());
  }

  @Override
  public void printStatus() {
    System.out.println("Received State");
  }
}
