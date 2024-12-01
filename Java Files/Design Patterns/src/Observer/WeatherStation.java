package Observer;

public class WeatherStation {
  public static void main(String[] args) {
    WeatherData weatherData = new WeatherData();

    ConsoleDisplay consoleDisplay = new ConsoleDisplay();
    weatherData.addObserver(consoleDisplay);
    weatherData.setMeasurements(80, 65, 30.4f);
  }
}
