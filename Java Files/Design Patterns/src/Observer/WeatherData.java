package Observer;

import java.util.ArrayList;

public class WeatherData implements AbstractObservable {
  private ArrayList<AbstractObserver> observers;

  private float temperature;
  private float humidity;
  private float pressure;

  public WeatherData() {
    this.observers = new ArrayList<AbstractObserver>();
  }

  @Override
  public void addObserver(AbstractObserver o) {
    this.observers.add(o);
  }

  @Override
  public void removeObserver(AbstractObserver o) {
    int i = this.observers.indexOf(o);
    if (i >= 0)
      this.observers.remove(o);
  }

  @Override
  public void notifyAllObservers() {
    for (int i = 0; i < observers.size(); i++) {
      AbstractObserver observer = observers.get(i);
      observer.update(this.temperature, this.humidity, this.pressure);
    }
  }

  public void setMeasurements(float temp, float hum, float pressure) {
    this.temperature = temp;
    this.humidity = hum;
    this.pressure = pressure;
    this.notifyAllObservers();
  }
}
