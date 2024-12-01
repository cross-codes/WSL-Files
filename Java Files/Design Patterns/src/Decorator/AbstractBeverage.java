package Decorator;

public abstract class AbstractBeverage {
  protected String description = "Unknown beverage";

  public String getDescription() {
    return this.description;
  }

  public abstract double cost();
}
