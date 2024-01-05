public class CallStack {
  public static void main(String[] args) {
    int beginning = 1;
    int end = 5;

    printStars(beginning, end);
  }

  public static void printStars(int beginning, int end) {
    while (beginning < end) {
      System.out.println("*");
      beginning++;
    }
  }
}

// The call stack of the program begins with the main method
// Each method has a corresponding frame.
// As more methods are called within the execution of the
// top most stack, they are added onto the stack. Their
// execution then occurs in accordance with the fact that
// the execution is that which is on top of the stack.
// Methods from the call stack are removed once their execution
// is complete
// Variables defined in the frame of the corresponding frame
// so their lifetime is that of the frame/method
