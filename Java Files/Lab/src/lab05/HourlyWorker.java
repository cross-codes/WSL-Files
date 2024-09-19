package lab05;

public class HourlyWorker extends Worker {
  private int hoursWorked;

  public HourlyWorker(String name, double salaryRate, int hoursWorked) {
    super(name, salaryRate);
    this.hoursWorked = hoursWorked;
  }

  @Override
  public double computePay() {
    return (this.hoursWorked > 60) ? 60 * 50 : this.hoursWorked * 50;
  }
}
