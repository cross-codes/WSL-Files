package lab09;

import java.util.logging.Logger;

public class Inventory {
  private static final Logger logger = Logger.getLogger(Inventory.class.getName());
  private int stock;

  public Inventory(int initialStock) {
    this.stock = initialStock;
  }

  public void addStock(int quantity) {
    assert quantity > 0 : "Quantity is not positive";
    logger.info("Adding stock with quantity: " + quantity);
    this.stock += quantity;
  }

  public void removeStock(int quantity) {
    assert (quantity > 0) && (this.stock - quantity >= 0) : "Invalid quantity specification";
    logger.info("Removing stock with quantity: " + quantity);
    this.stock -= quantity;
  }

  public int getStock() {
    return this.stock;
  }

  public static void main(String[] args) {
    Inventory inv = new Inventory(100);
    inv.addStock(120);
    try {
      inv.addStock(-1);
    } catch (AssertionError ex) {
      System.out.println("Assertion error 1 caught");
    }

    inv.removeStock(220);

    try {
      inv.removeStock(1);
    } catch (AssertionError ex) {
      System.out.println("Assertion error 2 caught");
    }
  }
}
