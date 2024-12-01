package Strategy;

public class Seller extends Role {
  public boolean isSatisfied(Product prod, double price) {
    return price - prod.getCost() > prod.getCost() * 0.2;
  }
}
