// An array list is used to store many values that are of
// the same type

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayLists {
  public static void main(String[] args) {
    // Use capital letters for defining the type of values
    // that a list can use
    // Variable types:
    //    (i) Primitive (Value type) -> int, double
    //    (ii) Reference type -> ArrayList
    ArrayList<String> list = new ArrayList<>();
    list.add("String is a reference type variable");
    // Once a list has been created, ArrayList assumes that
    // all variables contained in it are reference types
    // So an int is converted to an Integer once stored here
    ArrayList<Integer> integers = new ArrayList<>();
    int integer = 1;
    integers.add(integer);
    System.out.println(list.get(0));

    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter three or more names");
    ArrayList<String> stringList = new ArrayList<>();
    while (true) {
      String temp = scanner.nextLine();
      if (temp == "") {
        break;
      }
      stringList.add(temp);
    }
    System.out.println(stringList.get(2));
    scanner.close();
    System.out.println("The size of your arraylist was " + stringList.size());
  }
}
