public class Person {
  // Instance variables
  private String name; // private -> hidden (encapsulation)
  private int age;

  // Constructor - Method that creates the object
  // Always the same name as the class
  public Person(String initialName) {
    this.age = 0;
    this.name = initialName;
  }

  // Java implements a default constructor which creates
  // the object with uninitialized object variables
  // Object references will be null
  // Object primitives will be 0

  // This method does not affect others because
  // each object instantiated from a class has its own
  // instance variables
  public void growOlder() {
    this.age++;
  }

  public int returnAge() {
    return this.age;
  }

  public boolean isOfLegalAge() {
    return this.age >= 18;
  }

  public String toString() {
    return this.name + ", age " + this.age + " years";
  }
}
