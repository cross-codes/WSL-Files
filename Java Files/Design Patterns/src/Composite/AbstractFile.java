package Composite;

public interface AbstractFile {
  public void ls();

  public default boolean isComposite() {
    return false;
  }
}
