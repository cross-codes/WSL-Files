package lab07;

public class StaticOuter {
  String a = "Static outer string";
  static String b = "Static outer static string";

  void seeStaticInner() {
    System.out.println(new StaticInner().nonStatic);
    System.out.println(StaticInner.s);
  }

  static class StaticInner {
    String nonStatic = "Static inner nonstatic string";
    static String s = "Static inner static string";

    public static void main(String[] args) {
      System.out.println(b);
    }
  }
}

class SomeOther {
  public static void main(String[] args) {
    System.out.println(StaticOuter.StaticInner.s);
    StaticOuter.StaticInner si = new StaticOuter.StaticInner();
    System.out.println(si.nonStatic);

    // Equivalent
    System.out.println(si.s);
    System.out.println(StaticOuter.StaticInner.s);
  }
}
