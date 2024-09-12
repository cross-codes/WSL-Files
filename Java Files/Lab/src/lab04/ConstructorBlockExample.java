package lab04;

public class ConstructorBlockExample {
  {
    System.out.println("This is the first constructor block");
  }

  public ConstructorBlockExample() {
    System.out.println("This is no parameter constructor");
  }

  public ConstructorBlockExample(String param1) {
    System.out.println("This is a single parameter constructor");
  }

  {
    System.out.println("This is a second constructor block");
  }

  public static void main(String[] args) {
    ConstructorBlockExample constrBlockEx = new ConstructorBlockExample();
    ConstructorBlockExample constrBlock1 = new ConstructorBlockExample("param1");
  }
}
