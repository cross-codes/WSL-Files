package Strategy;

public class TestStrategy {

  public static void main(String[] args) {

    Product threeBhkDuplex = new Product("3-BHK DUPLEX APT", "3 Bedroom Duplex, DLF, Gurgaon", 20000000);
    Product twoBhkFlat = new Product("2-BHK FLAT", "2 Bedroom Flat, DLF, Gurgaon", 5000000);

    Person tim = new Person("Tim");
    Person allison = new Person("Allison");

    tim.setRole(new Buyer(5000000));
    allison.setRole(new Seller());

    if (!allison.satisfied(twoBhkFlat, 4000000)) {
      System.out.println("Offer of 4000000 is not good for the seller");
    }

    if (tim.satisfied(twoBhkFlat, 5000000)) {
      System.out.println("Offer of 5000000 is good for the buyer");
    }

    if (tim.satisfied(twoBhkFlat, 5000000) && allison.satisfied(twoBhkFlat, 5000000)) {
      System.out.println("They both agree with 5000000");
    }

    /*
     * To further demonstrate the capabilities of the strategy pattern, switch the
     * initial
     * Seller to the Buyer by calling setRole() on the Person object. It is possible
     * to switch
     * to a Buyer without modifying the Person object.
     */

    allison.setRole(new Buyer(30000000));
    if (allison.satisfied(threeBhkDuplex, 20000000)) {
      System.out.println("As a buyer Allison can afford the 3-BHK-DUPLEX Apartment");
    }
  }
}
