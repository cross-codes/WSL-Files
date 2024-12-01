package Adapter;

public class Adaptee {
  String name;

  public Adaptee(String name) {
    this.name = name;
  }

  public void walk() {
    System.out.println("... Walking");
  }

  public void sleep() {
    System.out.println("... Sleeping");
  }
}
