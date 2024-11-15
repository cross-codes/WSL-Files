package lab10;

public class RunnableExample {
  public static void main(String[] args) {
    MyTask task = new MyTask();
    Thread thread = new Thread(task);

    thread.start();

    System.out.println("Main thread is running independently");
  }
}

class MyTask implements Runnable {
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
