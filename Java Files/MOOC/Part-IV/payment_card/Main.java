public class Main {
  public static void main(String[] args) {
    PaymentCard paul = new PaymentCard(20);
    PaymentCard matt = new PaymentCard(30);
    paul.eatHeartily();
    matt.eatAffordably();
    System.out.println("Paul: " + paul);
    System.out.println("Matt: " + matt);
    paul.addMoney(20);
    matt.eatHeartily();
    System.out.println("Paul: " + paul);
    System.out.println("Matt: " + matt);
    paul.eatAffordably();
    paul.eatAffordably();
    matt.addMoney(50);
    System.out.println("Paul: " + paul);
    System.out.println("Matt: " + matt);
  }
}
