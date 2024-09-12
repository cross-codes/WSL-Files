package lab04;

public class BoxTest2 {
  public static void main(String[] args) {
    Box b1 = new Box(10, 40, 60);
    Box b2 = new Box(20, 30, 80);
    System.out.println(b1);
    System.out.println(b2);

    Box temp = b1;
    b1 = b2;
    b2 = temp;
    System.out.println(b1);
    System.out.println(b2);
  }
}
