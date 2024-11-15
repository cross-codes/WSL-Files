package lab08;

import java.util.LinkedList;

class StackOverflowException extends RuntimeException {
}

class StackUnderflowException extends RuntimeException {
}

public class Stack<T> {
  private final LinkedList<T> stk;
  public static int STACK_SIZE;
  private int pos;
  public final boolean isUnbound;

  public Stack() {
    STACK_SIZE = Integer.MAX_VALUE;
    this.stk = new LinkedList<>();
    this.pos = -1;
    this.isUnbound = true;
  }

  public Stack(int size) {
    STACK_SIZE = size;
    this.stk = new LinkedList<>();
    this.pos = -1;
    this.isUnbound = false;
  }

  public boolean push(T t) {
    if (this.pos == STACK_SIZE - 1) {
      throw new StackOverflowException();
    }

    this.stk.add(t);
    this.pos++;
    return true;
  }

  public T pop() {
    if (this.pos < 0)
      throw new StackUnderflowException();

    this.pos--;
    return this.stk.removeLast();
  }

  public T peek() {
    if (this.pos == -1)
      return null;
    return this.stk.get(this.pos);
  }

  public int size() {
    return this.pos + 1;
  }

  @Override
  public String toString() {
    return this.stk.toString();
  }
}
