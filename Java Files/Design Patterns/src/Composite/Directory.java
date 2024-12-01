package Composite;

import java.util.ArrayList;

public class Directory implements AbstractFile {
  ArrayList<AbstractFile> files = new ArrayList<>();

  @Override
  public boolean isComposite() {
    return true;
  }

  @Override
  public void ls() {
    files.forEach(AbstractFile::ls);
  }

  public void addFile(AbstractFile file) {
    files.add(file);
  }

  public void removeFile(AbstractFile file) {
    files.remove(file);
  }
}
