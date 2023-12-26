public class Calculations {
  public static void main(String[] args) {
    int first = 2;
    int second = 4;

    System.out.println(first + second);
    System.out.println(2 + second - first - second);
    // String concatenation is done with a '+' instead of a ','
    // This is because println is a function, and using ',' would count
    // as using multiple arguments
    System.out.println("Four: " + (2 + 2));
    System.out.println("But! Twenty-two: " + 2 + 2);

    // Type casting with division
    second = 3;
    double result = second / first;
    System.out.println(result); // Not a fraction
    double second_modded = 3.0;
    System.out.println(second_modded / first);

    // Type casting
    int third = 4;
    int fourth = 5;
    double result1 = (double) fourth / third;
    System.out.println(result1);
  }
}
