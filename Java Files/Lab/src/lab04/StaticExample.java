package lab04;

public class StaticExample {
  static {
    System.out.println("This is the first static block");
  }

  public StaticExample() {
    System.out.println("This is a constructor");
  }

  public static String staticString = "Static variable";

  static {
    System.out.println("This is the second static block and " + staticString);
  }

  static {
    staticMethod();
    System.out.println("This is the third static block");
  }

  public static void staticMethod() {
    System.out.println("This is a static method");
  }

  public static void staticMethod2() {
    System.out.println("This is static method2");
  }

  public static void main(String[] args) {
    StaticExample statEx = new StaticExample();
    StaticExample.staticMethod2();
  }
}
