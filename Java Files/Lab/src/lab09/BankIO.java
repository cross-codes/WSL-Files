package lab09;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BankIO {
  private BankIO() {
  }

  public static void readFile(String fileName, Bank bank) {
    try (Scanner in = new Scanner(new File(fileName))) {
      while (in.hasNext()) {
        BankAccount bac = readAccount(in);
        bank.add(bac);
      }
    } catch (FileNotFoundException ex) {
      ex.printStackTrace(System.err);
      System.exit(1);
    }

  }

  public static BankAccount readAccount(Scanner in) {
    int accNum = in.nextInt();
    double initBalance = in.nextDouble();
    System.err.println(accNum);
    System.err.println(initBalance);
    return new BankAccount(initBalance, accNum);
  }

  public static void write(Bank bank, String fileName) {
    try (PrintWriter out = new PrintWriter(fileName)) {
      out.println(bank.toString());
    } catch (FileNotFoundException ex) {
      System.err.println("Error: File not found");
      return;
    }
  }

  public static void main(String[] args) {
    write(new Bank(100), "nya.txt");
  }
}
