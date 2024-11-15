package AY2023;

import java.util.ArrayList;
import java.util.Comparator;

class Date implements Comparable<Date> {
  int month;
  int day;
  int year;

  Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
  }

  @Override
  public int compareTo(Date b) {
    int cmp1 = Integer.compare(this.year, b.year);
    if (cmp1 == 0) {
      int cmp2 = Integer.compare(this.month, b.month);
      if (cmp2 == 0) {
        return Integer.compare(this.day, b.day);
      } else return cmp2;
    } else return cmp1;
  }

  @Override
  public String toString() {
    return this.day + "/" + this.month + "/" + this.year;
  }
}

public class Q2B {
  public static void main(String[] args) {
    ArrayList<Date> dates =
        new ArrayList<>() {
          {
            add(new Date(12, 30, 2004));
            add(new Date(12, 31, 2006));
            add(new Date(12, 30, 2006));
          }
        };
    dates.sort(Comparator.naturalOrder());
    System.out.println(dates);
  }
}
