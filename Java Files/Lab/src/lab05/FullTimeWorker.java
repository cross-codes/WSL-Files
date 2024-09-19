package lab05;

public class FullTimeWorker extends Worker {
  private int hoursWorked;

  public FullTimeWorker(String name, double salaryRate, int hoursWorked) {
    super(name, salaryRate);
    this.hoursWorked = hoursWorked;
  }

  @Override
  public double computePay() {
    return (this.hoursWorked > 240) ? 240 * 100 : this.hoursWorked * 100;
  }
}
