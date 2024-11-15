package lab06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;

class Name {
  private String fname;
  private String mname;
  private String lname;

  Name(String name) {
    // Check if comma is the delimiter or semicolon
    boolean comma = false;
    int n = name.length();
    for (int i = 0; i < n; i++) {
      char c = name.charAt(i);
      if (c == ',') {
        comma = true;
        break;
      } else if (c == ';') {
        comma = false;
        break;
      }
    }

    // Split the parameter accordingly
    if (comma) {
      String[] augs = name.split(",");
      this.fname = augs[0];
      this.mname = augs[1];
      this.lname = augs[2];
    } else {
      String[] augs = name.split(";");
      this.fname = augs[2];
      this.mname = augs[1];
      this.lname = augs[0];
    }
  }

  // Accessors
  public String getFirstName() {
    return this.fname;
  }

  public String getMiddleName() {
    return this.mname;
  }

  public String getLastName() {
    return this.lname;
  }

  // Methods
  public String getName() {
    final StringBuilder sb = new StringBuilder();
    sb.append(this.fname).append(" ").append(this.mname).append(" ").append(this.lname).append(" ");
    return sb.toString();
  }

  // Overrides
  @Override
  public String toString() {
    return this.fname + this.mname + this.lname;
  }
}

class Student {
  private Name name;
  private int age;

  public Student(Name name, int age) {
    this.name = name;
    this.age = age;
  }

  // Accessors
  public Name getName() {
    return this.name;
  }

  public int getAge() {
    return this.age;
  }

  // Overrides
  @Override
  public String toString() {
    final StringBuilder sb = new StringBuilder();
    sb.append(this.name.getFirstName()).append(" ");
    sb.append(this.name.getMiddleName()).append(" ");
    sb.append(this.name.getLastName()).append(" ");
    sb.append(this.age);
    return sb.toString();
  }
}

class StudentList {
  public static Student[] list = new Student[10];
  public static int count = 0;

  public static void addStudent(Student std) {
    if (count >= 10) return;
    list[count] = std;
    count++;
  }

  public static Student[] getStudentsWithAge(int age) {
    Student[] res = new Student[count];
    int iterator = 0;
    for (int i = 0; i < count; i++) {
      if (list[i].getAge() == age) res[iterator++] = list[i];
    }
    if (iterator == 0) return null;
    else return res;
  }

  public static Student[] getStudentsWithLastName(String lastName) {
    Student[] res = new Student[count];
    int iterator = 0;
    for (int i = 0; i < count; i++) {
      String lname = list[i].getName().getLastName();
      if (lname.equals(lastName)) res[iterator++] = list[i];
    }
    if (iterator == 0) return null;
    else return res;
  }

  public static Student[] getStudentsInRange(int minAge, int maxAge) {
    Student[] res = new Student[count];
    int iterator = 0;
    for (int i = 0; i < count; i++) {
      int age = list[i].getAge();
      if (minAge <= age && maxAge >= age) res[iterator++] = list[i];
    }
    if (iterator == 0) return null;
    else return res;
  }
}

public class Test {
  public static Student readStudent() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Enter the first name: ");
    String name1 = br.readLine();
    System.out.print("Enter the middle name: ");
    String name2 = br.readLine();
    System.out.print("Enter the last name: ");
    String name3 = br.readLine();
    System.out.print("Enter the seperator: ");
    String sep = br.readLine();
    System.out.print("Enter the age: ");
    int age = Integer.parseInt(br.readLine());

    System.out.println();

    final StringBuilder name = new StringBuilder();
    name.append(name1).append(sep).append(name2).append(sep).append(name3).append(sep);
    return new Student(new Name(name.toString()), age);
  }

  public static void main(String[] args) throws IOException {
    for (int i = 0; i < 2; i++) StudentList.addStudent(readStudent());
    Student[] age20 = StudentList.getStudentsWithAge(20);
    if (!Objects.isNull(age20)) {
      for (int i = 0; i < age20.length; i++) System.out.println(age20[i]);
    }

    Student[] sharma = StudentList.getStudentsWithLastName("Sharma");
    if (!Objects.isNull(sharma)) {
      for (int i = 0; i < sharma.length; i++) System.out.println(sharma[i]);
    }

    Student[] range = StudentList.getStudentsInRange(16, 20);
    if (!Objects.isNull(range)) {
      for (int i = 0; i < range.length; i++) System.out.println(range[i]);
    }
  }
}
