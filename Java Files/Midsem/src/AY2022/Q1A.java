package AY2022;

import java.util.Scanner;

interface Draw {
  public void drawPattern(int n, String style, char symbol);
}

class Diamond implements Draw {
  @Override
  public void drawPattern(int n, String style, char symbol) {
    switch (style) {
      case "default":
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            System.out.print(symbol);
          }
          System.out.println();
        }
        System.out.println();
        break;

      case "pattern":
        this.drawPattern(n, symbol);
        break;

      default:
        System.out.println("Wrong choices");
    }
  }

  /**
   *
   *
   * <pre>
   * n = 3
   *            __$__
   *            _$$$_
   *            $$$$$
   *            _$$$_
   *            __$__
   * n = 2
   *             _$_
   *             $$$
   *             _$_
   * </pre>
   */
  public void drawPattern(int n, char symbol) {
    // Upper half
    for (int i = 1; i <= n; i++) {
      for (int j = n - i; j > 0; j--) System.out.print(" ");
      for (int k = 0; k < 2 * i - 1; k++) System.out.print(symbol);
      System.out.println();
    }
    // Lower half
    for (int i = 1; i < n; i++) {
      for (int colNum = 0; colNum < i; colNum++) System.out.print(" ");
      for (int k = 0; k < 2 * (n - i) - 1; k++) System.out.print(symbol);
      System.out.println();
    }
    System.out.println();
  }
}

class DiamondOutline extends Diamond {
  @Override
  public void drawPattern(int n, String style, char symbol) {
    switch (style) {
      case "default":
        super.drawPattern(n, "default", symbol);
        break;

      case "pattern":
        super.drawPattern(n, symbol);
        break;

      case "outline":
        this.drawPattern(n, symbol);
        break;

      default:
        System.out.println("Wrong choices");
    }
  }

  /**
   *
   *
   * <pre>
   * n = 3
   *            __$__
   *            _$_$_
   *            $___$
   *            _$_$_
   *            __$__
   * n = 2
   *             _$_
   *             $_$
   *             _$_
   * </pre>
   */
  @Override
  public void drawPattern(int n, char symbol) {
    // Upper half
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n - i; j++) System.out.print(" ");
      System.out.print(symbol);
      if (i != 1) {
        for (int k = 0; k < 2 * (i - 1) - 1; k++) System.out.print(" ");
        System.out.print(symbol);
      }
      System.out.println();
    }
    // Lower half
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) System.out.print(" ");
      System.out.print(symbol);
      if (i != n - 1) {
        for (int k = 0; k < 2 * i - 1; k++) System.out.print(" ");
        System.out.print(symbol);
      }
      System.out.println();
    }
    System.out.println();
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.print("Enter the number of rows: ");
    int rows = scan.nextInt();
    System.out.print("Enter the symbol you want to print: ");
    char symbol = scan.next().charAt(0);
    Diamond obj = new DiamondOutline();
    obj.drawPattern(rows, "default", symbol);
    obj.drawPattern(rows, "pattern", symbol);
    obj.drawPattern(rows, "outline", symbol);
    scan.close();
  }
}
