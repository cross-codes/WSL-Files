package lab05;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

class Person {
  private String name;
  private int age;

  public Person(String name, int age) {
    this.name = name;
    this.age = age;
  }

  private void greet() {
    System.out.println("Hello my name is: " + name);
  }
}

public class ReflectionExample1 {
  public static void main(String[] args) {
    try {
      Class<?> personClass = Person.class;
      System.out.println("Class name: " + personClass.getName());

      Field[] fields = personClass.getDeclaredFields();
      System.out.println("\nDeclared fields: ");

      for (Field field : fields) {
        System.out.println(field.getName() + " of type " + field.getType());
      }

      Method[] methods = personClass.getDeclaredMethods();
      System.out.println("\nDeclared methods: ");

      for (Method method : methods) {
        System.out.println(method.getName());
      }

      Constructor<?>[] constructors = personClass.getDeclaredConstructors();
      System.out.println("\nDeclared constructors: ");

      for (Constructor<?> constructor : constructors) {
        System.out.println(constructor.getName() + " of parameters " + constructor.getParameters());
      }

      Person p1 = new Person("ABC", 24);

      methods[0].setAccessible(true);
      methods[0].invoke(p1);

    } catch (Exception e) {
      e.printStackTrace(System.err);
    }
  }
}
