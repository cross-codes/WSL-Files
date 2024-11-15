package lab10;

import java.util.Random;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BankAccountRevamped {
  private long balance;
  private final Lock lock;
  private final Condition deposit;
  private final Condition withdraw;

  public BankAccountRevamped(long initialBalance) {
    this.balance = initialBalance;
    this.lock = new ReentrantLock(false);
    this.deposit = this.lock.newCondition();
    this.withdraw = this.lock.newCondition();
  }

  public void displayBalance() {
    System.out.println(this.balance);
  }

  public void depositMoney(long money) throws InterruptedException {
    this.lock.lock();
    try {
      this.balance += money;
      System.out.print("Deposit " + money + ", Current balance: ");
      this.displayBalance();
      this.withdraw.signal();
    } finally {
      lock.unlock();
    }
  }

  public void withdrawMoney(long money) throws InterruptedException {
    this.lock.lock();
    try {
      this.balance -= money;
      System.out.print("Withdraw " + money + ", Current balance: ");
      this.displayBalance();
      this.deposit.signal();
    } finally {
      lock.unlock();
    }
  }

  public static void main(String[] args) {
    BankAccountRevamped bankAccount = new BankAccountRevamped(1000L);
    new DepositorRevamped(bankAccount);
    new WithdrawerRevamped(bankAccount);
  }
}

class DepositorRevamped implements Runnable {
  private BankAccountRevamped bankAccount;

  public DepositorRevamped(BankAccountRevamped obj) {
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
        Thread.sleep(500);
      }
    } catch (InterruptedException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }
  }
}

class WithdrawerRevamped implements Runnable {
  private BankAccountRevamped bankAccount;

  public WithdrawerRevamped(BankAccountRevamped obj) {
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
        Thread.sleep(500);
      }
    } catch (InterruptedException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }
  }
}
