package lab08;

public class Anonymous {
  public Circle getCircle(int radius) {
    return new Circle(radius) {
      @Override
      public double area() {
        return super.area() * Math.PI;
      }
    };
  }

  public static void main(String[] args) {
    Anonymous p = new Anonymous();
    Circle w = p.getCircle(10);
    System.out.println(w.area());
  }
}

class Circle {
  private int rad;

  public Circle(int radius) {
    this.rad = radius;
  }

  public double area() {
    return this.rad * this.rad;
  }
}
