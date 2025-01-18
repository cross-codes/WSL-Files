package AY2022;

public class OpenBook3 {
  public static void main(String... args) {
    new OpenBook3().calc2(2);
    // SOME CODE HERE
  }

  public int calc1(int num) {
    try {
      return num / num;
    } catch (ArithmeticException ex) {
      ex.printStackTrace(System.err);
      return 0;
    }
  }

  public int calc2(int num) {
    try {
      int a[] = new int[num];
      a[5] = 30 / num;
      return a[5];
    } catch (NegativeArraySizeException ex) {
      ex.printStackTrace(System.err);
      return 0;
    } catch (IndexOutOfBoundsException ex) {
      ex.printStackTrace(System.err);
      return 0;
    } catch (ArithmeticException ex) {
      ex.printStackTrace(System.err);
      return 0;
    }
  }
}
