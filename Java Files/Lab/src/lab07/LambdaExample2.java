package lab07;

@FunctionalInterface
interface CheckEvenOdd {
  boolean check(int number);
}

public class LambdaExample2 {
  public static void main(String[] args) {
    CheckEvenOdd isEven = number -> number % 2 == 0;
    int[] numbers = { 4, 7, 10, 13 };

    for (int e : numbers) {
      if (isEven.check(e))
        System.out.println(e + " is even.");
      else
        System.out.println(e + " is odd.");
    }
  }
}
