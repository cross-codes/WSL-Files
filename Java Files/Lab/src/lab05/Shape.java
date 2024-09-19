package lab05;

public abstract class Shape {
  private String color;

  public Shape(String color) {
    this.color = color;
  }

  @Override
  public String toString() {
    return "Shape of the color = \"" + color + "\"";
  }

  public abstract double getArea();
}
