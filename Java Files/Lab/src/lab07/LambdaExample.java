package lab07;

import java.util.function.BiFunction;
import java.util.function.Supplier;

@FunctionalInterface
interface StringOperation {
  String process(String str);
}

@FunctionalInterface
interface IntegerOperation {
  int process(int num);
}

@FunctionalInterface
interface DoubleOperation {
  double process(double num);
}

public class LambdaExample {
  public static void main(String[] args) {
    StringOperation toUpperCase = (str) -> str.toUpperCase();
    System.out.println("Upper case: " + toUpperCase.process("hello"));

    IntegerOperation square = (num) -> num * num;
    System.out.println("Square: " + square.process(5));

    DoubleOperation half = (num) -> num / 2;
    System.out.println("Half: " + half.process(10.5));

    BiFunction<Integer, Integer, Integer> add = (a, b) -> a + b;
    System.out.println("Sum: " + add.apply(5, 3));

    Supplier<String> hello = () -> "Hello, World";
    System.out.println(hello.get());
  }
}
