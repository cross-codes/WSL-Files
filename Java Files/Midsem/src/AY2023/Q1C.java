package AY2023;

import java.util.ArrayList;
import java.util.List;

public class Q1C {
  public static <T> void copy(List<T> dest, List<T> src) {
    for (int i = 0; i < src.size(); i++) {
      dest.set(i, src.get(i));
    }
  }

  public static void main(String[] args) {
    List<Object> dest = new ArrayList<>();
    List<Long> src = new ArrayList<>();
    copy(dest, src);
  }
}
