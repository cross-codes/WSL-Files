package lab04;

public class Point {
  private double x;
  private double y;

  Point(double x, double y) {
    this.x = x;
    this.y = y;
  }

  public double getX() {
    return this.x;
  }

  public double getY() {
    return this.y;
  }

  public void setX(double x) {
    this.x = x;
  }

  public void setY(double y) {
    this.y = y;
  }

  @Override
  public String toString() {
    return "X = " + x + " Y = " + y;
  }

  public static void changeState(Point other) {
    other.setX(-20);
    other.setY(-20);
  }

  public static void changeReference(Point other) {
    other.x = 10;
    other = new Point(-20, -20);
    other.x = 20;
  }
}
