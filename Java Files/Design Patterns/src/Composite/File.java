package Composite;

public class File implements AbstractFile {
  @Override
  public void ls() {
    System.out.println("Listing file");
  }
}
