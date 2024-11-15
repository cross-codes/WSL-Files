package lab06;

public class RetailStore {
  private int[] itemId = {1001, 1002, 1003, 1004, 1005};
  private double[] price = {13.50, 18.00, 19.50, 25.50};

  private double computePrice(int value) {
    for (int i = 0; i < this.price.length; i++) {
      if (this.itemId[i] == value) return this.price[i];
    }
    return this.price[value];
  }

  public static void main(String[] args) {
    RetailStore one = new RetailStore();
    System.out.println("Price of item id 1002 is " + one.computePrice(1002));
    System.out.println("Price of item id 1004 is " + one.computePrice(1004));
  }
}
