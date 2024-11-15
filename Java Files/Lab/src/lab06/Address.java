package lab06;

public class Address {
  private String line1;
  private String line2;
  private String line3;
  private char[] city;
  private char[] state;
  private String pin;

  public Address(String paramName) {
    String[] augs = paramName.split("$");
    this.line1 = augs[0];
    this.line2 = augs[1];
    this.line3 = augs[2];
    this.city = augs[3].toCharArray();
    this.state = augs[4].toCharArray();
    this.pin = augs[5];
  }

  // Accessors
  public String getLine1() {
    return this.line1;
  }

  public String getLine2() {
    return this.line2;
  }

  public String getLine3() {
    return this.line3;
  }

  public String getCity() {
    return String.valueOf(this.city);
  }

  public String getState() {
    return String.valueOf(this.state);
  }

  public String getPin() {
    return this.pin;
  }
}
