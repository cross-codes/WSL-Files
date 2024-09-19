interface Callback {
  public int return1();
}

public abstract class Test implements Callback {
  public int return1() {
    return 1;
  }
}

class TestImpl extends Test {}
