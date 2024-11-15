package lab06;

public class RetailStoreExample extends NewRetailStore {
  public static void main(String[] args) {
    NewRetailStore retailOne = new NewRetailStore();
    String description = retailOne.fetchDescription(1004);
    String StringArray[];
    StringArray = description.split("\\s");
    String type = StringArray[2];
    System.out.println("The type of the item is " + type);
    System.out.println("The character at the starting position is " + type.charAt(0));
    int index = type.indexOf('-');
    String stringFromSubstring = type.substring(index + 1);
    System.out.println("The price computed using the substring method " + stringFromSubstring);
    String stringFromDouble = Double.toString(new NewRetailStore().computePrice(1004));
    System.out.println("The price computed using double.toString() " + stringFromDouble);

    int decimalIndex = stringFromDouble.indexOf('.');
    String val = stringFromDouble.substring(0, decimalIndex);
    if (val.equals(stringFromSubstring))
      System.out.println("The strings represent the same value " + val);
    else System.out.println("The strings represent a different numeric value");
  }
}
