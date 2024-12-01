package Decorator;

public class Beverage1 extends AbstractBeverage {
  public Beverage1() {
    this.description = "Espresso";
  }

  @Override
  public double cost() {
    return 1.75D;
  }
}
