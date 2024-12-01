package Decorator;

public class Main {
  public static void main(String... args) {
    AbstractBeverage beverage = new Beverage1();
    System.out.println(beverage.getDescription() + " $" + beverage.cost());

    beverage = new Condiment1(beverage);
    beverage = new Condiment2(beverage);
    beverage = new Condiment2(beverage);
    System.out.println(beverage.getDescription() + " $" + beverage.cost());
  }
}
