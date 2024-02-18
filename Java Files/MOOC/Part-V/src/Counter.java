public class Counter {
  private int value;

  public Counter() {
    this.value = 0;
  }

  public Counter(int startValue) {
    this.value = startValue;
  }

  public int value() {
    return this.value;
  }

  public void increase() {
    this.value++;
  }

  public void decrease() {
    this.value--;
  }

  public void increase(int increaseBy) {
    this.value += increaseBy;
  }

  public void decrease(int decreaseBy) {
    this.value -= decreaseBy;
  }
}
