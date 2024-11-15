package lab08;

public class TestStack {
  public static void main(String[] args) {
    Stack<Integer> stk = new Stack<>(5) {
      {
        this.push(1);
        this.push(3);
        this.push(2);
        this.push(4);
        this.push(5);
      }
    };

    try {
      stk.push(6);
    } catch (RuntimeException ex) {
      System.out.println("Exception caught");
    }

    System.out.println("Size of the stack is: " + stk.size());
    System.out.println(stk);

    for (int i = 3; i > -1; i--) {
      System.out.println(stk.pop());
    }

    System.out.println(stk.peek());
    System.out.println("Size of the stack is: " + stk.size());

    System.out.println(stk.pop());
    System.out.println(stk.peek());
    System.out.println("Size of the stack is: " + stk.size());

    try {
      stk.pop();
    } catch (RuntimeException ex) {
      System.out.println("Exception caught");
    }

    System.out.println("Size of the stack is: " + stk.size());
  }
}
