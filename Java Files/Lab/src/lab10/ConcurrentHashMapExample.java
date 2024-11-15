package lab10;

import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentHashMapExample {
  public static void main(String[] args) {
    ConcurrentHashMap<String, Character> map = new ConcurrentHashMap<>();

    String[] students = { "Akshaj", "Ishan", "Sanovar", "Tavish", "Aman", "Arnav" };
    Character[] grades = { 'A', 'A', 'B', 'C', 'C', 'C' };

    Runnable task1 = () -> {
      for (int i = 0; i < 2; i++) {
        map.put(students[i], grades[i]);
        System.out.println(Thread.currentThread().getName() + " caused the map to be: " + map);
      }

      try {
        Thread.sleep(100);
      } catch (Exception e) {
        e.printStackTrace();
      }
    };

    Runnable task2 = () -> {
      for (int i = 2; i < 4; i++) {
        map.put(students[i], grades[i]);
        System.out.println(Thread.currentThread().getName() + " caused the map to be: " + map);
      }

      try {
        Thread.sleep(100);
      } catch (Exception e) {
        e.printStackTrace();
      }
    };

    Runnable task3 = () -> {
      for (int i = 4; i < 6; i++) {
        map.put(students[i], grades[i]);
        System.out.println(Thread.currentThread().getName() + " caused the map to be: " + map);
      }

      try {
        Thread.sleep(100);
      } catch (Exception e) {
        e.printStackTrace();
      }
    };

    Thread t1 = new Thread(task1, "Thread 1");
    Thread t2 = new Thread(task2, "Thread 2");
    Thread t3 = new Thread(task3, "Thread 3");

    t1.start();
    t2.start();
    t3.start();

    try {
      t1.join();
      t2.join();
      t3.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    System.out.println("Final map: " + map);
  }
}
