package lab05;

public class Cylinder extends Circle {
  private double height;

  public Cylinder() {
    super();
    height = 1D;
  }

  public Cylinder(double radius, double height) {
    super(radius);
    this.height = height;
  }

  public double getHeight() {
    return this.height;
  }

  public void setHeight(double height) {
    this.height = height;
  }

  public double getVolume() {
    return this.getArea() * height;
  }
}
