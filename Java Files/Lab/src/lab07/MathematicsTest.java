package lab07;

import java.util.function.Predicate;

public class MathematicsTest {
  public static void main(String[] args) {
    Predicate<StudentMarks> pass = (student) -> student.marks > 70;

    StudentMarks john = new StudentMarks("John", 100);
    StudentMarks garry = new StudentMarks("Garry", 10);
    StudentMarks alex = new StudentMarks("Alex", 75);

    StudentMarks[] array = { john, garry, alex };

    for (StudentMarks e : array) {
      if (pass.test(e)) {
        System.out.println(e.name);
      }
    }

  }

  private static class StudentMarks {
    public String name;
    public int marks;

    public StudentMarks(String name, int marks) {
      this.name = name;
      this.marks = marks;
    }
  }
}
