package lab05;

public class Manager extends Employee {
  private String department;

  public Manager(String name, double salary, String dept) {
    super(name, salary);
    this.department = dept;
  }

  // Accessor methods
  public String getName() {
    return super.getName();
  }

  public double getSalary() {
    return super.getSalary();
  }

  public String getDepartment() {
    return this.department;
  }

  // Mutator methods
  public void setName(String name) {
    super.setName(name);
  }

  public void setSalary(double salary) {
    super.setSalary(salary);
  }

  public void setDepartment(String department) {
    this.department = department;
  }

  @Override
  public String toString() {
    return "Name : "
        + super.getName()
        + " Salary : "
        + super.getSalary()
        + " Department : "
        + this.department;
  }
}
