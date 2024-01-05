public class Astrology {
  public static void main(String[] args) {
    christmasTree(12);
  }

  public static void printSpaces(int number) {
    for (int i = 0; i < number; i++) System.out.print(" ");
  }

  public static void printStars(int number) {
    for (int i = 0; i < number; i++) System.out.print("*");
    System.out.println();
  }

  public static void printTriangle(int size) {
    for (int i = 1; i <= size; i++) {
      printSpaces(size - i);
      printStars(i);
    }
  }

  public static void christmasTree(int height) {
    for (int i = height - 1; i != 0; i--) {
      printSpaces(i);
      printStars(2 * (height - i) - 1);
    }
    for (int j = 0; j < 2; j++) {
      printSpaces(height - 2);
      printStars(3);
    }
  }
}
