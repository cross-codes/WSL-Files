package lab10;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

public class ProcessPractice1 {
  public static void main(String[] args) throws IOException, InterruptedException {
    ProcessBuilder pb = new ProcessBuilder("neovide");
    Process process = pb.start();

    process.waitFor(15, TimeUnit.SECONDS);

    process.destroyForcibly();
  }
}
