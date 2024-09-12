package lab04;

public class StaticBlock {
  static int[] values = initializeArray(10);

  private static int[] initializeArray(int n) {
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
  }

  void listValues() {
    for (int value : values) {
      System.out.println(value);
    }
  }

  public static void main(String[] args) {
    StaticBlock example = new StaticBlock();
    System.out.println("\nFirst Object");
    example.listValues();

    example = new StaticBlock();
    System.out.println("\nSecond Object");
    example.listValues();
  }
}
