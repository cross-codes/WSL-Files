/**
 * Creational pattern: Abstract Factory
 *
 * Provide an interface for creating families of related or dependent objects
 * without specifying their concrete classes.
 * A hierarchy that encapsulates: many possible "platforms", and the
 * construction of a suite of "products".
 * The new operator considered harmful.
 * 
 * Problem: If an application is to be portable, it needs to encapsulate
 * platform dependencies. These "platforms" might include: windowing system,
 * operating system, database, etc. Too often, this encapsulation is not
 * engineered in advance, and lots of #ifdef case statements with options for
 * all currently supported platforms begin to procreate like rabbits throughout
 * the code.
 * 
 * The application can wholesale replace the entire family of products simply by
 * instantiating a different concrete instance of the abstract factory.
 * 
 * Because the service provided by the factory object is so pervasive, it is
 * routinely implemented as a Singleton.
 * 
 */

// Abstract factory interface
public interface AbstractCarFactory {
  public Car makeCar();
}

// Concrete Factories
class NorthAmericaCarFactory implements AbstractCarFactory {
  @Override
  public Car makeCar() {
    return new Sedan();
  }
}

class EuropeCarFactory implements AbstractCarFactory {
  @Override
  public Car makeCar() {
    return new Hatchback();
  }
}

// Abstract Product interface
interface Car {
  public void assemble();
}

// Concrete Product classes
class Sedan implements Car {
  @Override
  public void assemble() {
    System.out.println("Assembling sedan car");
  }
}

class Hatchback implements Car {
  @Override
  public void assemble() {
    System.out.println("Assembling hatchback car");
  }
}
