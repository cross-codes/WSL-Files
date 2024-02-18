public class Person {
  private String name;
  private int age;
  private int weight;
  private int height;

  public Person(String name) {
    this.name = name;
    this.age = 0;
    this.weight = 0;
    this.height = 0;
  }

  public void printPerson() {
    System.out.println(this.name + " is " + this.age + " years old");
  }

  public void growOlder() {
    this.age++;
  }

  public boolean isAdult() {
    return this.age >= 18;
  }

  public double bodyMassIndex() {
    double heightInMeters = this.height / 100.0;

    return this.weight / (heightInMeters * heightInMeters);
  }

  @Override
  public String toString() {
    return this.name + " is " + this.age + " years old, their BMI is " + this.bodyMassIndex();
  }

  public void setHeight(int height) {
    this.height = height;
  }

  public int getHeight() {
    return this.weight;
  }

  public int getWeight() {
    return this.weight;
  }

  public void setWeight(int weight) {
    this.weight = weight;
  }

  public String getName() {
    return this.name;
  }
}
