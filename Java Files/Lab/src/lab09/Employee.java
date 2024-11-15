package lab09;

import java.util.logging.Logger;

public class Employee {
  private static final Logger logger = Logger.getLogger(Employee.class.getName());
  private String name;
  private double salary;

  public Employee(String name, double initialSalary) {
    logger.info("Employee name: " + name + " , Salary: " + initialSalary);
    this.name = name;
    this.salary = initialSalary;
  }

  public void updateSalary(double newSalary) {
    logger.info("Current salary: " + this.salary + " , New salary: " + newSalary);
    this.salary = newSalary;
  }

  public double getSalary() {
    return this.salary;
  }

  public static void main(String[] args) {
    new Employee("Akshaj", 200);
  }
}
