package lab05;

public class Employee {
  private String name;
  private double salary;

  public Employee(String name, double salary) {
    this.name = name;
    this.salary = salary;
  }

  // Accessor methods
  public String getName() {
    return this.name;
  }

  public double getSalary() {
    return this.salary;
  }

  // Mutator methods
  public void setName(String name) {
    this.name = name;
  }

  public void setSalary(double salary) {
    this.salary = salary;
  }

  @Override
  public String toString() {
    return "Name: " + this.name + " Salary: " + this.salary;
  }
}
