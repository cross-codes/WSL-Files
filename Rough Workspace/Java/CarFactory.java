public interface CarFactory {
  Engine getEngine();

  Wheels getWheels();
}

class SedanCarFactory implements CarFactory {
  public Engine getEngine() {
    return new SedanEngine(20);
  }

  public Wheels getWheels() {
    return new SedanWheels(20);
  }
}

abstract class Engine {
  String type;
}

class SedanEngine extends Engine {
  double lengthMeters;

  public SedanEngine(double length) {
    this.lengthMeters = length;
  }
}

abstract class Wheels {
  String type;
}

class SedanWheels extends Wheels {
  double radius;

  public SedanWheels(double radius) {
    this.radius = radius;
  }
}
