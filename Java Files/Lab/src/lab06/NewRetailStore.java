package lab06;

public class NewRetailStore {
  private int[] itemId;
  private double[] price;
  private String itemName[];

  public NewRetailStore() {
    this.itemId = new int[] {1001, 1002, 1003, 1004, 1005};
    this.price = new double[] {950.00, 750.00, 450.00, 350.00, 250.00};
    this.itemName =
        new String[] {
          "Yonex Tennis Racket-950", "Yonex Badminton Racket-750",
          "Silvers Badminton Racket-450", "Cosco Badminton shuttle-350",
          "Cosco Tennis Racket-250"
        };
  }

  protected double computePrice(int value) {
    for (int i = 0; i < price.length; ++i) {
      if (itemId[i] == value) return price[i];
    }
    return price[value];
  }

  protected String fetchDescription(int value) {
    for (int i = 0; i < price.length; ++i) {
      if (itemId[i] == value) return itemName[i];
    }
    return null;
  }
}
