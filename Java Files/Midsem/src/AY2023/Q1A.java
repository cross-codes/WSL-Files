package AY2023;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class Q1A {
  public static <V extends Collection<E>, E extends Comparable<E>> E max(V xs) {
    Iterator<E> xi = xs.iterator();
    E res = xi.next();
    while (xi.hasNext()) {
      E curObj = xi.next();
      if (res.compareTo(curObj) < 0) res = curObj;
    }
    return res;
  }

  public static void main(String[] args) {
    ArrayList<Integer> lst =
        new ArrayList<>() {
          {
            add(1);
            add(2);
            add(45);
            add(3);
          }
        };

    System.out.println(max(lst));
  }
}
