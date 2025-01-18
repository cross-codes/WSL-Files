package AY2022;

import java.io.IOException;
import java.util.Scanner;

public class OpenBook2 {
  public static void main(String... args) throws IOException {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the two numbers: ");
    String[] input = sc.nextLine().split(" ");
    Number[] numbers = new Number[2];

    for (int i = 0; i < input.length; i++) {
      if (input[i].lastIndexOf(".") >= 0)
        numbers[i] = Float.parseFloat(input[i]);
      else
        numbers[i] = Integer.parseInt(input[i]);
    }

    NumericComparator<Number, Number> comp = new NumericComparator<>(numbers[0], numbers[1]);
    int result = comp.compare();
    if (result > 0)
      System.out.println(numbers[0]);
    else
      System.out.println(numbers[1]);
    sc.close();
  }
}

class NumericComparator<U extends Number, V extends Number> {
  public Double firstNumber;
  public Double secondNumber;

  public NumericComparator(U u, V v) {
    this.firstNumber = u.doubleValue();
    this.secondNumber = v.doubleValue();
  }

  public int compare() {
    return this.firstNumber.compareTo(this.secondNumber);
  }
}
