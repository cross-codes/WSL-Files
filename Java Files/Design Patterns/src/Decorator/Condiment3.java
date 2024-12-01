package Decorator;

public class Condiment3 extends AbstractCondimentDecorator {
  public Condiment3(AbstractBeverage beverage) {
    super(beverage);
  }

  public String getDescription() {
    return beverage.getDescription() + ", cookies";
  }

  public double cost() {
    return 0.1D + beverage.cost();
  }
}
