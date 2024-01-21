package Constructors;

class Parent1 {
  Parent1() {
    System.out.println("Non-Param of parent");
  }

  Parent1(int x) {
    System.out.println("Param of Parent " + x);
  }
}

class Child1 extends Parent1 {
  Child1() {
    System.out.println("Non-Param of Child");
  }

  Child1(int y) {
    System.out.println("Param of Child");
  }

  Child1(int x, int y) {
    super(x);
    System.out.println("2 Param of Child " + y);
  }
}

public class ParametrizedConst {
  public static void main(String[] args) {
    Child1 c = new Child1(10, 20);
  }
}
