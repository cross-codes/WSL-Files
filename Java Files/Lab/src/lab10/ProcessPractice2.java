package lab10;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProcessPractice2 {
  public static void main(String[] args) throws IOException {
    ProcessBuilder pb = new ProcessBuilder("ls");
    Process process = pb.start();

    BufferedReader out = new BufferedReader(new InputStreamReader(process.getInputStream()));
    BufferedReader err = new BufferedReader(new InputStreamReader(process.getErrorStream()));

    while (true) {
      String line = out.readLine();
      if (line != null) {
        System.out.println(line);
      } else
        break;
    }

    while (true) {
      String line = err.readLine();
      if (line != null) {
        System.out.println(line);
      } else
        break;
    }
  }
}
