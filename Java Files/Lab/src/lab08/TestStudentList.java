package lab08;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.ListIterator;

public class TestStudentList {
  public static void main(String[] args) {
    ArrayList<Student> studentList = new ArrayList<>();

    studentList.add(new Student("Ramesh", "Male", 18));
    studentList.add(new Student("Reeta", "Female", 19));
    studentList.add(new Student("Seema", "Female", 18));
    studentList.add(new Student("Suresh", "Male", 20));

    System.out.println("Original contents: ");

    Iterator<Student> it = studentList.iterator();
    while (it.hasNext()) {
      Student element = it.next();
      System.out.println(element);
    }

    System.out.println();
    ListIterator<Student> lit = studentList.listIterator();
    while (lit.hasNext()) {
      Student element = lit.next();
      if (element.getGender().equals("Male"))
        element.setName("Mr." + element.getName());
      else
        element.setName("Miss." + element.getName());
      lit.set(element);
    }

    it = studentList.iterator();
    while (it.hasNext()) {
      Student element = it.next();
      System.out.println(element);
    }

    System.out.println();

    System.out.println("Modified list backwards");
    while (lit.hasPrevious()) {
      Student element = lit.previous();
      System.out.println(element);
    }

    System.out.println();
  }
}
