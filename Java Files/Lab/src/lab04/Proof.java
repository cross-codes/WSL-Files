package lab04;

public class Proof {
  public static void main(String[] args) {
    Runtime runtime = Runtime.getRuntime();

    long memSet = runtime.totalMemory() - runtime.freeMemory();

    for (int i = 0; i < 10000; i++) {
      System.out.print(String.valueOf(10));
    }

    System.out.println();

    long memRes = runtime.totalMemory() - runtime.freeMemory();
    System.out.println("Memory used: " + (memRes - memSet) + " bytes");
  }
}
