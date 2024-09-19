package lab02;

public class TestTax {
  public static void main(String[] args) {
    TaxOnSalary tax1 = new TaxOnSalary();
    TaxOnSalary tax2 = new TaxOnSalary(true);

    try {

      tax1.inputSalary();
      tax2.inputSalary();
      System.out.println("Calculated tax of the first user: " + tax1.calculateTax());
      System.out.println("Calculated tax of the second user: " + tax2.calculateTax());
    } catch (Throwable t) {
      t.printStackTrace(System.err);
      return;
    }
  }
}
