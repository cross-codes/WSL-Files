package lab10;

import java.io.IOException;

public class ProcessPractice3 {
  public static void main(String[] args) throws IOException, InterruptedException {
    ProcessBuilder pb1 = new ProcessBuilder("touch", "testFile.txt");
    ProcessBuilder pb2 = new ProcessBuilder("rm", "testFile.txt");
    Process create = pb1.start();
    create.waitFor();
    Process delete = pb2.start();
    delete.waitFor();
  }
}
