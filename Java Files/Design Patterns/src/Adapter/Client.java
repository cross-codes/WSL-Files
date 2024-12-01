package Adapter;

public class Client {
  public static void compete(Target target) {
    target.walk();
    target.run();
    target.fetch();
  }

  public static void main(String... args) {
    Adaptee adaptee = new Adaptee("coswell");
    Adapter adapter = new Adapter(adaptee);
    compete(adapter);
  }
}
