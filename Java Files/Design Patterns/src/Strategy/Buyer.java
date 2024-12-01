package Strategy;

public class Buyer extends Role {
  private double limit;

  public Buyer(double limit) {
    this.limit = limit;
  }

  public boolean isSatisfied(Product prod, double price) {
    return price < this.limit && price < prod.getCost() * 2;
  }
}
