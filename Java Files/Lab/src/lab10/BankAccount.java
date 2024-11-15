package lab10;

import java.util.Random;

public class BankAccount {
  private long balance;
  private boolean deposit = true;

  public BankAccount(long initialBalance) {
    this.balance = initialBalance;
  }

  public void displayBalance() {
    System.out.println(this.balance);
  }

  public synchronized void depositMoney(long money) throws InterruptedException {
    while (!deposit)
      this.wait();

    this.balance += money;
    this.deposit = false;
    System.out.print("Deposit " + money + ", Current balance: ");
    this.displayBalance();
    this.notify();
  }

  public synchronized void withdrawMoney(long money) throws InterruptedException {
    while (deposit)
      this.wait();

    this.balance -= money;
    System.out.print("Withdraw " + money + ", Current balance: ");
    this.displayBalance();
    this.deposit = true;
    this.notify();
  }

  public static void main(String[] args) {
    BankAccount bankAccount = new BankAccount(1000L);
    new Depositor(bankAccount);
    new Withdrawer(bankAccount);
  }
}

class Depositor implements Runnable {
  private BankAccount bankAccount;

  public Depositor(BankAccount obj) {
    bankAccount = obj;
    new Thread(this, "Depositor").start();
  }

  @Override
  public void run() {
    try {
      Random random = new Random();
      for (int i = 0; i < 10; i++) {
        long money = random.nextInt(5) * 100L;
        this.bankAccount.depositMoney(money);
      }
    } catch (InterruptedException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }
  }
}

class Withdrawer implements Runnable {
  private BankAccount bankAccount;

  public Withdrawer(BankAccount obj) {
    bankAccount = obj;
    new Thread(this, "Withdrawer").start();
  }

  @Override
  public void run() {
    try {
      Random random = new Random();
      for (int i = 0; i < 10; i++) {
        long money = random.nextInt(5) * 100L;
        this.bankAccount.withdrawMoney(money);
      }
    } catch (InterruptedException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }
  }
}
