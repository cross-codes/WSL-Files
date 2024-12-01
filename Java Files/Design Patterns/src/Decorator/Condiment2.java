package Decorator;

public class Condiment2 extends AbstractCondimentDecorator {
  public Condiment2(AbstractBeverage beverage) {
    super(beverage);
  }

  public String getDescription() {
    return beverage.getDescription() + ", milk";
  }

  public double cost() {
    return 0.5D + beverage.cost();
  }
}
