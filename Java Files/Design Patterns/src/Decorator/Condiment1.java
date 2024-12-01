package Decorator;

public class Condiment1 extends AbstractCondimentDecorator {
  public Condiment1(AbstractBeverage beverage) {
    super(beverage);
  }

  public String getDescription() {
    return beverage.getDescription() + ", mocha";
  }

  public double cost() {
    return 0.2D + beverage.cost();
  }
}
