package lab05;

public class TestEmployeeManager {
  public static void main(String[] args) {
    Employee e1 = new Employee("ABC", 500D);
    Employee e2 = new Employee("BCD", 550D);

    System.out.println(e1);
    System.out.println(e2);

    Manager m1 = new Manager("CDE", 600D, "CSIS");
    Manager m2 = new Manager("DEF", 565D, "Physics");

    System.out.println(m1);
    System.out.println(m2);
  }
}
