public class Arrays {
  public static void main(String[] args) {
    int[] numbers = new int[3]; // Arrays are not dynamic in size
    numbers[0] = 2;
    numbers[2] = 5;
    System.out.println(numbers[1]); // Defaults to 0
  }
}
