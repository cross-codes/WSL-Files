import java.util.ArrayList;

public class RemoveContains {
  public static void main(String[] args) {
    ArrayList<String> list = new ArrayList<>();

    list.add("First");
    list.add("Second");
    list.add("Third");

    list.remove(1);

    System.out.println("Index 0 so the first value: " + list.get(0));
    System.out.println("Index 1 so the second value: " + list.get(1));

    boolean found = list.contains("Second");
    if (found) {
      System.out.println("Second was found");
    }
  }
}
