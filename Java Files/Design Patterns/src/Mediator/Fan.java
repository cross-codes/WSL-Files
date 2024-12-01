package Mediator;

public class Fan {
  private Mediator mediator;
  public boolean isOn = false;

  public Fan(Mediator mediator) {
    this.mediator = mediator;
  }

  public void turnOn() {
    mediator.start();
    isOn = true;
  }

  public void turnOff() {
    isOn = false;
    mediator.stop();
  }
}
