package AY2023;

interface Parent {
  default void welcome(String msg) {
    System.out.println("welcome() of Parent --> " + msg);
  }
}

interface Child extends Parent {
  @Override
  default void welcome(String msg) {
    System.out.println("welcome() of Child --> " + msg);
  }
}

class ChildImpl1 implements Child {}

class ParentImp1 implements Parent {
  @Override
  public void welcome(String msg) {
    System.out.println("welcome() of ParentImp1");
  }
}

class OverridingParent extends ParentImp1 {
}

class OverridingChild extends OverridingParent implements Child {}

public class Q4A {
  public static void main(String[] args) {
    OverridingChild obj = new OverridingChild();
    obj.welcome("Hello");
  }
}
