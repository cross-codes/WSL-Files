package lab05;

public abstract class Worker {
  private String name;
  private double salaryRate;

  public Worker(String name, double salaryRate) {
    this.name = name;
    this.salaryRate = salaryRate;
  }

  public String getName() {
    return this.name;
  }

  public double getSalary() {
    return this.salaryRate;
  }

  public abstract double computePay();
}
