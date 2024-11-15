package lab08;

public class TestBank {
  public static void main(String[] args) {
    Bank bank = new Bank(100);

    Account ishan = new Account(3L, 200, "Ishan");

    bank.addAccount(new Account(1L, 200, "Akshaj"));
    bank.addAccount(new Account(2L, 200, "Sania"));
    bank.addAccount(ishan);

    bank.removeAccount(ishan);

    System.out.println(bank.deposit(2L, 200));
    System.out.println(bank.withdraw(1L, 300));
  }
}
