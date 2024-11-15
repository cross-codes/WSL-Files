package lab08;

import java.util.ArrayList;
import java.util.Iterator;

public class Bank {
  private ArrayList<Account> accounts;
  int maxActive;

  public Bank(int maxActive) {
    this.accounts = new ArrayList<>();
    this.maxActive = maxActive;
  }

  public boolean addAccount(Account newOne) {
    return accounts.add(newOne);
  }

  public boolean removeAccount(Account newOne) {
    return accounts.remove(newOne);
  }

  public double deposit(long accountNumber, double amt) {
    Iterator<Account> it = this.accounts.iterator();

    while (it.hasNext()) {
      Account element = it.next();
      if (element.getAccountNumber() == accountNumber) {
        double currBalance = element.getBalance();
        element.setBalance(currBalance + amt);
        return currBalance + amt;
      }
    }

    return -1D;
  }

  public double withdraw(long accountNumber, double amt) {
    Iterator<Account> it = this.accounts.iterator();

    while (it.hasNext()) {
      Account element = it.next();
      if (element.getAccountNumber() == accountNumber) {
        double currBalance = element.getBalance();
        if (currBalance < amt)
          return -1D;
        element.setBalance(currBalance - amt);
        return currBalance - amt;
      }
    }

    return -1D;
  }

  @Override
  public String toString() {
    final StringBuilder sb = new StringBuilder("Current bank details");
    Iterator<Account> it = this.accounts.iterator();
    while (it.hasNext()) {
      sb.append(it.next().toString()).append("\n");
    }
    return sb.toString();
  }
}
