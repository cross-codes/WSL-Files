package lab05;

public class Country {
  private String name;
  private String capital;
  private long population;

  public Country(String name) {
    this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public String getCapital() {
    return this.capital;
  }

  public void setCapital(String capital) {
    this.capital = capital;
  }

  public long getPopulation() {
    return this.population;
  }

  public void setPopulation(long population) {
    this.population = population;
  }

  @Override
  public String toString() {
    return "Country [name="
        + this.name
        + " capital="
        + this.capital
        + " population="
        + this.population
        + "]";
  }

  public static void main(String[] args) {
    Country India = new Country("India");
    India.setCapital("New Delhi");
    India.setPopulation(1200000000);
    System.out.println(India);
  }
}
