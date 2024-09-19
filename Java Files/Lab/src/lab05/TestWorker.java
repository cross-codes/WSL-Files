package lab05;

public class TestWorker {
  public static void main(String[] args) {
    Worker w1 = new FullTimeWorker("ABC", 12D, 12);
    Worker w2 = new HourlyWorker("BCD", 10D, 65);

    System.out.println(w1.computePay());
    System.out.println(w2.computePay());
  }
}
