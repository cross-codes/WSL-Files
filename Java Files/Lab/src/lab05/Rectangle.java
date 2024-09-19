package lab05;

public class Rectangle extends Shape {
  private int length;
  private int width;

  public Rectangle(String color, int length, int width) {
    super(color);
    this.length = length;
    this.width = width;
  }

  @Override
  public String toString() {
    return "Rectangle of length = "
        + this.length
        + " and width = "
        + this.width
        + ", subclass of "
        + super.toString();
  }

  @Override
  public double getArea() {
    return this.length * this.width;
  }
}
