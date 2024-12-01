package State;

public interface AbstractPackageState {
  public void next(Package pkg);

  public void prev(Package pkg);

  public void printStatus();
}
