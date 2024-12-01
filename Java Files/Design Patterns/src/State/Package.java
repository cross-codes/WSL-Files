package State;

public class Package {
  private AbstractPackageState state = new OrderedState();

  public AbstractPackageState getState() {
    return this.state;
  }

  public void setState(AbstractPackageState state) {
    this.state = state;
  }

  public void previousState() {
    state.prev(this);
  }

  public void nextState() {
    state.next(this);
  }

  public void printStatus() {
    state.printStatus();
  }
}
