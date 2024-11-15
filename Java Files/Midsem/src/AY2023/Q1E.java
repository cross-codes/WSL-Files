package AY2023;

import java.util.List;

public class Q1E {
  public static <T> void swap(List<T> list, int i, int j) {
    T obj1 = list.get(i);
    T obj2 = list.get(j);
    T temp = obj1;
    list.set(i, obj2);
    list.set(j, temp);
  }

  public static void main(String[] args) {}
}
