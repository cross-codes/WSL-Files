public class FitByte {
  private int age;
  private int restingHeartRate;

  public FitByte(int age, int restingHeartRate) {
    this.age = age;
    this.restingHeartRate = restingHeartRate;
  }

  public double targetHeartRate(double percentageOfMaximum) {
    double maximum = 206.3 - (0.711 * this.age);
    return (maximum - this.restingHeartRate) * (percentageOfMaximum) + this.restingHeartRate;
  }
}
