package lab10;

public class ThreadExample {
  public static void main(String[] args) {
    MyThread thread = new MyThread();
    thread.start();

    System.out.println("Main thread is running independently");
  }
}

class MyThread extends Thread {
  @Override
  public void run() {
    for (int i = 0; i < 5; i++) {
      System.out.println("Task: " + i);
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
