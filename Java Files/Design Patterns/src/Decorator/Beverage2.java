package Decorator;

public class Beverage2 extends AbstractBeverage {
  public Beverage2() {
    this.description = "DarkRoast";
  }

  @Override
  public double cost() {
    return 1.99D;
  }
}
