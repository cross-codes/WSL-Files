package lab04;

public class TestCircle {
  public static void main(String[] args) {
    Circle c1 = new Circle(2.3);
    c1.area();

    Circle.getCircumference(2.3);

    Circle c2 = new Circle(3.45);
    c2.area();
    c2.getCircumference(3.45); // Discouraged
  }
}
