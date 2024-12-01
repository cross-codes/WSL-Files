package Strategy;

public class Person {

  private String name;
  private Role role;

  public Person(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  public Role getRole() {
    return role;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setRole(Role role) {
    this.role = role;
  }

  public boolean satisfied(Product product, double offer) {
    return role.isSatisfied(product, offer);
  }
}
