package lab05;

public class Circle {
  private double radius;
  private String color;

  public Circle() {
    this.radius = 1D;
    this.color = "red";
  }

  public Circle(double r) {
    this.radius = r;
    this.color = "red";
  }

  public Circle(double r, String c) {
    this.radius = r;
    this.color = c;
  }

  public double getRadius() {
    return this.radius;
  }

  public String getColor() {
    return this.color;
  }

  public double getArea() {
    return this.radius * this.radius * Math.PI;
  }
}
