package lab09;

public strictfp class TemperatureConverter {
  public static double celsiusToFarenheit(double celsius) {
    assert celsius > -273.15 : "Invalid temperature specified";
    return (9D * celsius / 5D + 32D);
  }

  public static double farenheitToCelsius(double fahrenheit) {
    assert fahrenheit > -459.67 : "Invalid temperature specified";
    return ((fahrenheit - 32D) * 5D / 9D);
  }

  public static void main(String[] args) {
    System.out.println(celsiusToFarenheit(-201));
    System.out.println(celsiusToFarenheit(-400));
  }
}
