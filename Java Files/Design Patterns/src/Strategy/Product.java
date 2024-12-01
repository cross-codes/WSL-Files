package Strategy;

public class Product {
  private String name;
  private String description;
  private double cost;

  public Product(String name, String desc, double cost) {
    this.name = name;
    this.description = desc;
    this.cost = cost;
  }

  public String getName() {
    return this.name;
  }

  public String getDescription() {
    return this.description;
  }

  public double getCost() {
    return this.cost;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setDescription(String desc) {
    this.description = desc;
  }

  public void setCost(double cost) {
    this.cost = cost;
  }
}
