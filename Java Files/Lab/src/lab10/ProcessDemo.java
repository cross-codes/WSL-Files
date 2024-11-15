package lab10;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ProcessDemo {
  public static void main(String[] args) {
    try {
      ProcessBuilder builder = new ProcessBuilder("ping", "-c", "3", "google.com");
      Process process = builder.start();

      BufferedReader stdInput = new BufferedReader(new InputStreamReader(process.getInputStream()));
      BufferedReader stdError = new BufferedReader(new InputStreamReader(process.getErrorStream()));

      String line;
      System.out.println("Standard Output: ");
      while ((line = stdInput.readLine()) != null) {
        System.out.println(line);
      }

      System.out.println("Error output (if any): ");
      while ((line = stdError.readLine()) != null) {
        System.out.println(line);
      }

      int exitCode = process.waitFor();
      System.out.println("Process exited with code: " + exitCode);
    } catch (Throwable t) {
      t.printStackTrace(System.err);
    }
  }
}
