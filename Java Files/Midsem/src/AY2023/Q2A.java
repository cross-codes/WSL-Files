package AY2023;

import java.util.Arrays;
import java.util.Collection;

class Stack<E> {
  private E[] elements;
  private int size;
  private static final int DEFAULT_INITIAL_CAPACITY = 16;

  public Stack() {
    elements = (E[]) new Object[DEFAULT_INITIAL_CAPACITY];
  }

  public void push(E obj) {
    ensureCapacity();
    elements[size] = obj;
    size++;
  }

  public E pop() {
    if (size == 0) {
      throw new RuntimeException();
    }
    E result = elements[--size];
    elements[size] = null;
    return result;
  }

  // Can also use public void pushAll(Iterable<? extends E> sequence) {}

  public <V extends E> void pushAll(Iterable<V> sequence) {
    for (E e : sequence) push(e);
  }

  public void popAll(Collection<? super E> dst) {
    while (!isEmpty()) dst.add(pop());
  }

  public boolean isEmpty() {
    return this.size == 0;
  }

  public void ensureCapacity() {
    if (size == elements.length) elements = Arrays.copyOf(elements, 2 * elements.length);
  }
}
