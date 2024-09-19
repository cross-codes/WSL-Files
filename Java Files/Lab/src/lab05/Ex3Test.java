package lab05;

class A {
  public int a = 100;
}

class B extends A {
  public int a = 80;
}

class C extends B {
  public int a = 60;
}

class D extends C {
  public int a = 40;
}

class E extends D {
  public int a = 10;

  public void show() {
    int a = 0;
    System.out.println("a in local scope: " + a);
    System.out.println("a in scope E: " + this.a);
    System.out.println("a in scope D: " + super.a);

    // Casting 'this' to a supertype or a subtype
    // Casting to a supertype is safe
    // Casting to a subtype needs a check
    System.out.println("a in scope C: " + ((C) this).a);
    System.out.println("a in scope B: " + ((B) this).a);
    System.out.println("a in scope A: " + ((A) this).a);
  }
}

public class Ex3Test {
  public static void main(String[] args) {
    new E().show();
    A a1 = new E(); // new A(), B(), C() would throw a ClassCastException
    D d1 = (D) a1;
    System.out.println(d1.a);
  }
}
