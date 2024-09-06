package lab02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TaxOnSalary {
  private double salary;
  private boolean isPANSubmitted;

  public TaxOnSalary() {
    this.salary = 0D;
    this.isPANSubmitted = false;
  }

  public TaxOnSalary(boolean state) {
    this.salary = 1e3;
    this.isPANSubmitted = state;
  }

  // Getters
  public double getSalary() {
    return this.salary;
  }

  public boolean getPANstatus() {
    return this.isPANSubmitted;
  }

  // Methods
  public void inputSalary() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Enter the salary of the selected user: ");
    this.salary = Double.parseDouble(br.readLine());
  }

  public double calculateTax() {
    double mult = 0D;

    if (salary < 18e4 && isPANSubmitted) mult = 0D;
    else if (salary < 18e4 && !isPANSubmitted) mult = 0.05;
    else if (salary > 18e4 && salary < 5e5) mult = 0.1;
    else if (salary > 5e5 && salary < 1e6) mult = 0.2;
    else mult = 0.3;

    return this.salary * mult;
  }
}
