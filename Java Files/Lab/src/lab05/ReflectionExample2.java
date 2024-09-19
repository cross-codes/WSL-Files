package lab05;

import java.lang.reflect.Field;

class Employee2 {
  private String name;
  private double salary;

  public Employee2(String name, double salary) {
    this.name = name;
    this.salary = salary;
  }

  public void displayInfo() {
    System.out.println("Employee name: " + this.name + ", Salary: " + this.salary);
  }
}

public class ReflectionExample2 {
  public static void main(String[] args) {
    try {
      Employee2 emp = new Employee2("John", 50000);
      emp.displayInfo();

      Class<?> empClass = emp.getClass();

      Field salaryField = empClass.getDeclaredField("salary");
      salaryField.setAccessible(true);
      salaryField.set(emp, 75000);

      emp.displayInfo();
    } catch (Exception e) {
      e.printStackTrace(System.err);
    }
  }
}
