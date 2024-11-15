package lab08;

public class Account {
  private long accountNumber;
  private double balance;
  private String name;

  public Account(long accountNumber, double balance, String name) {
    this.accountNumber = accountNumber;
    this.balance = balance;
    this.name = name;
  }

  public long getAccountNumber() {
    return this.accountNumber;
  }

  public double getBalance() {
    return this.balance;
  }

  public String getName() {
    return this.name;
  }

  public void setAccountNumber(long newNumber) {
    this.accountNumber = newNumber;
  }

  public void setBalance(double newBalance) {
    this.balance = newBalance;
  }

  public void setName(String name) {
    this.name = name;
  }

  @Override
  public String toString() {
    return "Name: " + this.name + ", Account number: " + this.accountNumber + ", Balance: " + this.balance;
  }
}
