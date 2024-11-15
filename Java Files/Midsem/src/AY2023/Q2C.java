package AY2023;

import java.util.function.BinaryOperator;
import java.util.function.Function;
import java.util.function.Predicate;

public class Q2C {
  public static void main(String[] args) {
    final Predicate<Integer> LAMBDA_ONE = (a) -> a > 0;
    final BinaryOperator<Integer> LAMBDA_TWO = (a, b) -> a + b;
    final Function<Integer, Integer> LAMBDA_THREE = (a) -> a;
  }
}
