package AY2022;

import java.util.Random;

public class Q1B {
  public static void main(String[] args) {
    Random random = new Random();
    int conseq = 0, iter = 0;
    while (true) {
      if (random.nextInt(2) == 1) {
        conseq++;
        System.out.println("TRUE");
        if (conseq == 3) break;
      } else {
        conseq = 0;
        System.out.println("FALSE");
      }
      iter++;
    }
    System.out.printf("It took %d iterations to generate 3 consecutive Trues", iter);
  }
}
