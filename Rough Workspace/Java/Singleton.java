/**
 * Creational pattern: Singleton
 *
 * Ensure a class has only one instance and provide a global point of access to
 * it. Encapsulated "just in time initialization".
 * 
 * Problem: Application needs one, and only one, instance of an object.
 * Additionally, lazy initialization and global access are necessary.
 * 
 * 1. Define a private static attribute in the "single instance" class.
 * 2. Define a public static accessor function in the class.
 * 3. Do "lazy initialization" (creation on first use) in the accessor function.
 * 4. Define all constructors to be protected or private.
 * 5. Clients may only use the accessor function to manipulate the Singleton.
 * 
 */
public class Singleton {
  private static Singleton instance;
  public String s;

  private Singleton() {
    this.s = "Hello world";
  }

  public Singleton getInstace() {
    if (instance == null)
      instance = new Singleton();

    return instance;
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    throw new CloneNotSupportedException();
  }
}
