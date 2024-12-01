package Adapter;

public class Adapter implements Target {
  private Adaptee adaptee;

  public Adapter(Adaptee adaptee) {
    this.adaptee = adaptee;
  }

  public void walk() {
    System.out.println("this dog can walk");
    adaptee.walk();
  }

  public void run() {
    System.out.println("this dog doesn't run");
    adaptee.sleep();
  }

  public void fetch() {
    System.out.println("this dog doesn't fetch");
    adaptee.sleep();
  }
}
