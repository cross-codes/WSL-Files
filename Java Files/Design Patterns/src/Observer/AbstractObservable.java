package Observer;

public interface AbstractObservable {
  public void addObserver(AbstractObserver o);

  public void removeObserver(AbstractObserver o);

  public void notifyAllObservers();
}
