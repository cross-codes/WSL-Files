public class PaymentCard {
  private double balance;

  public PaymentCard(double openingBalance) {
    this.balance = openingBalance;
  }

  public String toString() {
    return "The card has a balance of " + Double.toString(balance) + " euros";
  }

  public void eatAffordably() {
    if (this.balance - 2.60 < 0) {
      return;
    }
    this.balance -= 2.60;
  }

  public void eatHeartily() {
    if (this.balance - 4.60 < 0) {
      return;
    }
    this.balance -= 4.60;
  }

  public void addMoney(double amount) {
    if (amount < 0) {
      return;
    }
    this.balance += amount;
    if (this.balance > 150) {
      this.balance = 150;
    }
  }
}
