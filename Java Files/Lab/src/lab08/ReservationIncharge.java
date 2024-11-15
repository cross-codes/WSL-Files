package lab08;

import java.util.LinkedList;

public class ReservationIncharge {
  public static void main(String[] args) {
    ReservationCounter counter = ReservationCounter.InitializeCounter();
    counter.standInLine("Amitab");
    counter.standInLine("amir");
    counter.standInLine("salman");
    counter.standInLine("Tom Cruise");
    for (int position = 0; position < counter.customersInLine(); position++) {
      System.out.println("customer at " + (position + 1)
          + " place in line is "
          + counter.checkTheCustomerAt(position));
    }
    System.out.println("Ticket given to " + counter.giveTicket());
    counter.leaveTheLine();
    counter.standInLine("Emma Watson");
    System.out.println("Ticket given to " + counter.giveTicket());
    counter.leaveTheLine();
    System.out.println("customer in position 2 is " + counter.checkTheCustomerAt(1));
    System.out.println("Still there are " + counter.customersInLine() + " people in line");
  }
}

class ReservationCounter {
  LinkedList<String> ReservationQueue;

  private ReservationCounter() {
    this.ReservationQueue = new LinkedList<>();
  }

  public void standInLine(String customer) {
    this.ReservationQueue.add(customer);
  }

  public void leaveTheLine() {
    this.ReservationQueue.remove();
  }

  public String giveTicket() {
    return (String) this.ReservationQueue.getFirst();
  }

  public String checkTheCustomerAt(int position) {
    return (String) this.ReservationQueue.get(position);
  }

  public static ReservationCounter InitializeCounter() {
    return new ReservationCounter();
  }

  public int customersInLine() {
    return this.ReservationQueue.size();
  }
}
