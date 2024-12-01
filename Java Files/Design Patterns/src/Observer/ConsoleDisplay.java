package Observer;

public class ConsoleDisplay implements AbstractObserver {
  private float temperature;
  private float humidity;

  @Override
  public void update(float temp, float hum, float pressure) {
    this.temperature = temp;
    this.humidity = hum;
    this.display();
  }

  public void display() {
    System.out.println("Current Conditions: " + this.temperature + "F degree and "
        + this.humidity + "% humidity");
  }
}
