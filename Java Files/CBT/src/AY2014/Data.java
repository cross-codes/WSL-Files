package AY2014;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Data {
  private int result;
  private boolean pChance;
  private boolean mChance;
  private int nop;
  private Object lock;

  public Data() {
    try (BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {

    } catch (IOException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }
  }
}
