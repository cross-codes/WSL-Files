package Mediator;

public class Mediator {
  private Button button;
  private Fan fan;
  private PowerSupplier powerSupplier;

  public void press() {
    if (fan.isOn) {
      fan.turnOff();
    } else {
      fan.turnOn();
    }
  }

  public void start() {
    powerSupplier.turnOn();
  }

  public void stop() {
    powerSupplier.turnOff();
  }
}
