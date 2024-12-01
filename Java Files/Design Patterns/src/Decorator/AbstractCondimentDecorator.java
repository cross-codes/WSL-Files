package Decorator;

public abstract class AbstractCondimentDecorator extends AbstractBeverage {
  protected AbstractBeverage beverage;

  public AbstractCondimentDecorator(AbstractBeverage beverage) {
    this.beverage = beverage;
  }

  public abstract String getDescription();

  public abstract double cost();
}
